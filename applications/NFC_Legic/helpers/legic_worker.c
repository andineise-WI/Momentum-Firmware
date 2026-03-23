#include "legic_worker.h"

#include <nfc/nfc_poller.h>
#include <nfc/protocols/iso14443_3a/iso14443_3a.h>
#include <nfc/protocols/iso14443_3a/iso14443_3a_poller.h>
#include <nfc/protocols/iso15693_3/iso15693_3.h>
#include <nfc/protocols/iso15693_3/iso15693_3_poller.h>

#define TAG "LegicWorker"

typedef struct {
    LegicApp* app;
    LegicWorkerCallback callback;
    void* context;
    bool is_write;
} LegicWorkerContext;

static LegicWorkerContext worker_ctx;

static NfcCommand legic_worker_poller_callback_14443a(NfcGenericEventEx event, void* context) {
    furi_assert(context);
    LegicWorkerContext* ctx = context;
    LegicApp* app = ctx->app;
    LegicCardData* card = &app->card_data;

    NfcEvent* nfc_event = event.parent_event_data;
    if(nfc_event->type != NfcEventTypePollerReady) {
        return NfcCommandContinue;
    }

    Iso14443_3aPoller* poller = event.poller;

    // Activate card and get UID
    Iso14443_3aData activated_data = {};
    Iso14443_3aError activate_err = iso14443_3a_poller_activate(poller, &activated_data);
    if(activate_err != Iso14443_3aErrorNone) {
        if(ctx->callback) ctx->callback(LegicWorkerEventFail, ctx->context);
        return NfcCommandStop;
    }

    card->rf_std = LegicRfStdIso14443A;
    card->uid_len = activated_data.uid_len;
    memcpy(card->uid, activated_data.uid, activated_data.uid_len);

    if(!ctx->is_write) {
        // Read mode
        BitBuffer* tx_buf = bit_buffer_alloc(16);
        BitBuffer* rx_buf = bit_buffer_alloc(256);

        uint16_t offset = 0;

        for(uint16_t block = 0; block < 256 && offset < LEGIC_MAX_DUMP_SIZE; block++) {
            bit_buffer_reset(tx_buf);
            uint8_t read_cmd[2] = {0x30, (uint8_t)block};
            bit_buffer_copy_bytes(tx_buf, read_cmd, sizeof(read_cmd));

            Iso14443_3aError error = iso14443_3a_poller_send_standard_frame(
                poller, tx_buf, rx_buf, 50);

            if(error != Iso14443_3aErrorNone) break;

            size_t rx_bytes = bit_buffer_get_size_bytes(rx_buf);
            if(rx_bytes == 0) break;

            size_t copy_len = rx_bytes;
            if(offset + copy_len > LEGIC_MAX_DUMP_SIZE) {
                copy_len = LEGIC_MAX_DUMP_SIZE - offset;
            }
            bit_buffer_write_bytes(rx_buf, card->raw_data + offset, copy_len);
            offset += copy_len;

            if(rx_bytes >= 16) {
                block += 3;
            }
        }

        card->raw_data_len = offset;
        card->fs_version = LegicFsVersionAdvant;
        card->segment_count = 0;

        bit_buffer_free(tx_buf);
        bit_buffer_free(rx_buf);

        if(ctx->callback) ctx->callback(LegicWorkerEventReadDone, ctx->context);
    } else {
        // Write mode
        BitBuffer* tx_buf = bit_buffer_alloc(16);
        BitBuffer* rx_buf = bit_buffer_alloc(256);

        bool write_ok = true;
        uint16_t offset = 0;

        for(uint16_t block = 0; block < 256 && offset < card->raw_data_len; block++) {
            bit_buffer_reset(tx_buf);
            uint8_t write_cmd[6] = {0xA2, (uint8_t)block, 0, 0, 0, 0};
            size_t remain = card->raw_data_len - offset;
            size_t chunk = remain > 4 ? 4 : remain;
            memcpy(&write_cmd[2], card->raw_data + offset, chunk);
            bit_buffer_copy_bytes(tx_buf, write_cmd, 2 + chunk);

            Iso14443_3aError error = iso14443_3a_poller_send_standard_frame(
                poller, tx_buf, rx_buf, 50);

            if(error != Iso14443_3aErrorNone) {
                write_ok = false;
                break;
            }
            offset += 4;
        }

        bit_buffer_free(tx_buf);
        bit_buffer_free(rx_buf);

        if(ctx->callback) {
            ctx->callback(
                write_ok ? LegicWorkerEventWriteDone : LegicWorkerEventFail, ctx->context);
        }
    }

    return NfcCommandStop;
}

static NfcCommand legic_worker_poller_callback_15693(NfcGenericEventEx event, void* context) {
    furi_assert(context);
    LegicWorkerContext* ctx = context;
    LegicApp* app = ctx->app;
    LegicCardData* card = &app->card_data;

    NfcEvent* nfc_event = event.parent_event_data;
    if(nfc_event->type != NfcEventTypePollerReady) {
        return NfcCommandContinue;
    }

    Iso15693_3Poller* poller = event.poller;

    Iso15693_3Data* activated_data = iso15693_3_alloc();
    Iso15693_3Error activate_err = iso15693_3_poller_activate(poller, activated_data);
    if(activate_err != Iso15693_3ErrorNone) {
        iso15693_3_free(activated_data);
        if(ctx->callback) ctx->callback(LegicWorkerEventFail, ctx->context);
        return NfcCommandStop;
    }

    card->rf_std = LegicRfStdIso15693;
    card->uid_len = ISO15693_3_UID_SIZE;
    memcpy(card->uid, activated_data->uid, ISO15693_3_UID_SIZE);

    if(!ctx->is_write) {
        // Read mode
        Iso15693_3SystemInfo sys_info = {};
        Iso15693_3Error error = iso15693_3_poller_get_system_info(poller, &sys_info);

        uint16_t num_blocks = 64;
        uint8_t block_size = 4;

        if(error == Iso15693_3ErrorNone && (sys_info.flags & ISO15693_3_SYSINFO_FLAG_MEMORY)) {
            num_blocks = sys_info.block_count + 1;
            block_size = sys_info.block_size + 1;
        }

        uint16_t offset = 0;
        for(uint16_t block = 0; block < num_blocks && offset < LEGIC_MAX_DUMP_SIZE; block++) {
            uint8_t block_data[32] = {0};
            error = iso15693_3_poller_read_block(poller, block_data, block, block_size);
            if(error != Iso15693_3ErrorNone) break;

            size_t copy_len = block_size;
            if(offset + copy_len > LEGIC_MAX_DUMP_SIZE) {
                copy_len = LEGIC_MAX_DUMP_SIZE - offset;
            }
            memcpy(card->raw_data + offset, block_data, copy_len);
            offset += copy_len;
        }

        card->raw_data_len = offset;
        card->fs_version = LegicFsVersionAdvant;
        card->segment_count = 0;

        iso15693_3_free(activated_data);
        if(ctx->callback) ctx->callback(LegicWorkerEventReadDone, ctx->context);
    } else {
        // Write mode
        Iso15693_3SystemInfo sys_info = {};
        Iso15693_3Error error = iso15693_3_poller_get_system_info(poller, &sys_info);

        uint8_t block_size = 4;
        if(error == Iso15693_3ErrorNone && (sys_info.flags & ISO15693_3_SYSINFO_FLAG_MEMORY)) {
            block_size = sys_info.block_size + 1;
        }

        BitBuffer* tx_buf = bit_buffer_alloc(64);
        BitBuffer* rx_buf = bit_buffer_alloc(64);

        bool write_ok = true;
        uint16_t offset = 0;

        for(uint16_t block = 0; offset < card->raw_data_len; block++) {
            bit_buffer_reset(tx_buf);

            uint8_t frame[40];
            uint8_t frame_len = 0;
            frame[frame_len++] =
                ISO15693_3_REQ_FLAG_DATA_RATE_HI | ISO15693_3_REQ_FLAG_T4_ADDRESSED;
            frame[frame_len++] = ISO15693_3_CMD_WRITE_BLOCK;
            memcpy(&frame[frame_len], activated_data->uid, ISO15693_3_UID_SIZE);
            frame_len += ISO15693_3_UID_SIZE;
            frame[frame_len++] = (uint8_t)block;

            size_t remain = card->raw_data_len - offset;
            size_t chunk = remain > block_size ? block_size : remain;
            memcpy(&frame[frame_len], card->raw_data + offset, chunk);
            frame_len += chunk;

            bit_buffer_copy_bytes(tx_buf, frame, frame_len);
            error = iso15693_3_poller_send_frame(poller, tx_buf, rx_buf, 50);

            if(error != Iso15693_3ErrorNone) {
                write_ok = false;
                break;
            }
            offset += block_size;
        }

        bit_buffer_free(tx_buf);
        bit_buffer_free(rx_buf);
        iso15693_3_free(activated_data);

        if(ctx->callback) {
            ctx->callback(
                write_ok ? LegicWorkerEventWriteDone : LegicWorkerEventFail, ctx->context);
        }
    }

    return NfcCommandStop;
}

void legic_worker_start_read(LegicApp* app, LegicWorkerCallback callback, void* context) {
    worker_ctx.app = app;
    worker_ctx.callback = callback;
    worker_ctx.context = context;
    worker_ctx.is_write = false;

    NfcProtocol protocol = app->card_data.nfc_protocol;
    if(protocol == NfcProtocolInvalid) {
        protocol = NfcProtocolIso14443_3a;
    }

    app->poller = nfc_poller_alloc(app->nfc, protocol);

    if(protocol == NfcProtocolIso14443_3a) {
        nfc_poller_start_ex(app->poller, legic_worker_poller_callback_14443a, &worker_ctx);
    } else if(protocol == NfcProtocolIso15693_3) {
        nfc_poller_start_ex(app->poller, legic_worker_poller_callback_15693, &worker_ctx);
    }
}

void legic_worker_start_write(LegicApp* app, LegicWorkerCallback callback, void* context) {
    worker_ctx.app = app;
    worker_ctx.callback = callback;
    worker_ctx.context = context;
    worker_ctx.is_write = true;

    NfcProtocol protocol = app->card_data.nfc_protocol;
    if(protocol == NfcProtocolInvalid) {
        protocol = NfcProtocolIso14443_3a;
    }

    app->poller = nfc_poller_alloc(app->nfc, protocol);

    if(protocol == NfcProtocolIso14443_3a) {
        nfc_poller_start_ex(app->poller, legic_worker_poller_callback_14443a, &worker_ctx);
    } else if(protocol == NfcProtocolIso15693_3) {
        nfc_poller_start_ex(app->poller, legic_worker_poller_callback_15693, &worker_ctx);
    }
}

void legic_worker_stop(LegicApp* app) {
    if(app->poller) {
        nfc_poller_stop(app->poller);
        nfc_poller_free(app->poller);
        app->poller = NULL;
    }
}
