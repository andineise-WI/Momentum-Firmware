#include "legic_file.h"

#include <flipper_format/flipper_format.h>
#include <toolbox/path.h>

#define TAG "LegicFile"

#define LEGIC_FILE_VERSION 1

bool legic_file_save(LegicApp* app) {
    furi_assert(app);
    LegicCardData* card = &app->card_data;

    bool result = false;
    FlipperFormat* ff = flipper_format_file_alloc(app->storage);

    // Generate filename from UID
    FuriString* filename = furi_string_alloc();
    for(uint8_t i = 0; i < card->uid_len; i++) {
        furi_string_cat_printf(filename, "%02X", card->uid[i]);
    }

    FuriString* full_path = furi_string_alloc();
    furi_string_printf(
        full_path, "%s/%s%s", LEGIC_APP_FOLDER, furi_string_get_cstr(filename), LEGIC_APP_EXTENSION);

    do {
        if(!flipper_format_file_open_always(ff, furi_string_get_cstr(full_path))) {
            FURI_LOG_E(TAG, "Failed to open file for writing");
            break;
        }

        // Header
        if(!flipper_format_write_header_cstr(ff, LEGIC_APP_FILE_TYPE, LEGIC_FILE_VERSION)) break;

        // UID
        if(!flipper_format_write_hex(ff, "UID", card->uid, card->uid_len)) break;

        // RF Standard
        uint32_t rf_std = (uint32_t)card->rf_std;
        if(!flipper_format_write_uint32(ff, "RF Standard", &rf_std, 1)) break;

        // FS Version
        uint32_t fs_ver = (uint32_t)card->fs_version;
        if(!flipper_format_write_uint32(ff, "FS Version", &fs_ver, 1)) break;

        // NFC Protocol
        uint32_t protocol = (uint32_t)card->nfc_protocol;
        if(!flipper_format_write_uint32(ff, "NFC Protocol", &protocol, 1)) break;

        // Segment count
        uint32_t seg_count = (uint32_t)card->segment_count;
        if(!flipper_format_write_uint32(ff, "Segments", &seg_count, 1)) break;

        // Raw data
        uint32_t data_len = (uint32_t)card->raw_data_len;
        if(!flipper_format_write_uint32(ff, "Data Length", &data_len, 1)) break;
        if(card->raw_data_len > 0) {
            if(!flipper_format_write_hex(ff, "Data", card->raw_data, card->raw_data_len)) break;
        }

        // Balance info
        if(card->has_value_field) {
            uint32_t balance = (uint32_t)card->balance;
            if(!flipper_format_write_uint32(ff, "Balance", &balance, 1)) break;
        }

        result = true;
        furi_string_set(app->file_path, full_path);
        furi_string_set(app->file_name, filename);

        FURI_LOG_I(TAG, "Saved to %s", furi_string_get_cstr(full_path));
    } while(false);

    flipper_format_free(ff);
    furi_string_free(filename);
    furi_string_free(full_path);

    return result;
}

bool legic_file_load(LegicApp* app, const char* path) {
    furi_assert(app);
    furi_assert(path);
    LegicCardData* card = &app->card_data;

    bool result = false;
    FlipperFormat* ff = flipper_format_file_alloc(app->storage);

    do {
        if(!flipper_format_file_open_existing(ff, path)) {
            FURI_LOG_E(TAG, "Failed to open file");
            break;
        }

        // Verify header
        uint32_t version = 0;
        FuriString* file_type = furi_string_alloc();
        if(!flipper_format_read_header(ff, file_type, &version)) {
            furi_string_free(file_type);
            break;
        }
        if(furi_string_cmp_str(file_type, LEGIC_APP_FILE_TYPE) != 0 ||
           version != LEGIC_FILE_VERSION) {
            FURI_LOG_E(TAG, "Invalid file type or version");
            furi_string_free(file_type);
            break;
        }
        furi_string_free(file_type);

        // UID
        memset(card, 0, sizeof(LegicCardData));
        // Read UID — try max size, actual length determined by read
        if(!flipper_format_read_hex(ff, "UID", card->uid, LEGIC_UID_MAX_LEN)) {
            // Try shorter UID lengths
            if(!flipper_format_rewind(ff)) break;
            if(!flipper_format_read_header(ff, NULL, NULL)) break;
            // Try 7 bytes
            if(flipper_format_read_hex(ff, "UID", card->uid, 7)) {
                card->uid_len = 7;
            } else if(flipper_format_read_hex(ff, "UID", card->uid, 4)) {
                card->uid_len = 4;
            } else {
                break;
            }
        } else {
            card->uid_len = LEGIC_UID_MAX_LEN;
        }

        // RF Standard
        uint32_t rf_std = 0;
        if(!flipper_format_read_uint32(ff, "RF Standard", &rf_std, 1)) break;
        card->rf_std = (LegicRfStandard)rf_std;

        // FS Version
        uint32_t fs_ver = 0;
        if(!flipper_format_read_uint32(ff, "FS Version", &fs_ver, 1)) break;
        card->fs_version = (LegicFsVersion)fs_ver;

        // NFC Protocol
        uint32_t protocol = 0;
        if(!flipper_format_read_uint32(ff, "NFC Protocol", &protocol, 1)) break;
        card->nfc_protocol = (NfcProtocol)protocol;

        // Segment count
        uint32_t seg_count = 0;
        if(!flipper_format_read_uint32(ff, "Segments", &seg_count, 1)) break;
        card->segment_count = (uint8_t)seg_count;

        // Data
        uint32_t data_len = 0;
        if(!flipper_format_read_uint32(ff, "Data Length", &data_len, 1)) break;
        card->raw_data_len = (uint16_t)data_len;

        if(card->raw_data_len > 0 && card->raw_data_len <= LEGIC_MAX_DUMP_SIZE) {
            if(!flipper_format_read_hex(ff, "Data", card->raw_data, card->raw_data_len)) break;
        }

        // Balance (optional)
        uint32_t balance = 0;
        if(flipper_format_read_uint32(ff, "Balance", &balance, 1)) {
            card->balance = (int32_t)balance;
            card->has_value_field = true;
        }

        furi_string_set_str(app->file_path, path);

        result = true;
        FURI_LOG_I(TAG, "Loaded from %s", path);
    } while(false);

    flipper_format_free(ff);

    return result;
}
