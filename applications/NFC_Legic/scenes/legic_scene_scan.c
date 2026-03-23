#include "../legic_app_i.h"

#define TAG "LegicScan"

static void legic_scene_scan_scanner_callback(NfcScannerEvent event, void* context) {
    furi_assert(context);
    LegicApp* app = context;

    if(event.type == NfcScannerEventTypeDetected) {
        // Check if any detected protocol is ISO14443A or ISO15693
        for(size_t i = 0; i < event.data.protocol_num; i++) {
            NfcProtocol protocol = event.data.protocols[i];
            if(protocol == NfcProtocolIso14443_3a || protocol == NfcProtocolIso15693_3) {
                app->card_data.nfc_protocol = protocol;
                view_dispatcher_send_custom_event(
                    app->view_dispatcher, LegicCustomEventScanResult);
                return;
            }
        }
    }
}

void legic_scene_scan_on_enter(void* context) {
    LegicApp* app = context;

    popup_set_header(app->popup, "Scanning...", 64, 20, AlignCenter, AlignTop);
    popup_set_text(app->popup, "Place LEGIC card\non Flipper's back", 64, 35, AlignCenter, AlignTop);

    view_dispatcher_switch_to_view(app->view_dispatcher, LegicViewPopup);

    // Start NFC scanner
    app->scanner = nfc_scanner_alloc(app->nfc);
    nfc_scanner_start(app->scanner, legic_scene_scan_scanner_callback, app);
    app->scan_active = true;

    notification_message(app->notifications, &sequence_blink_start_blue);
}

bool legic_scene_scan_on_event(void* context, SceneManagerEvent event) {
    LegicApp* app = context;
    bool consumed = false;

    if(event.type == SceneManagerEventTypeCustom) {
        if(event.event == LegicCustomEventScanResult) {
            // Stop scanner
            if(app->scan_active) {
                nfc_scanner_stop(app->scanner);
                nfc_scanner_free(app->scanner);
                app->scanner = NULL;
                app->scan_active = false;
            }

            notification_message(app->notifications, &sequence_success);

            // Read basic card info via poller
            app->card_loaded = true;
            scene_manager_next_scene(app->scene_manager, LegicSceneCardInfo);
            consumed = true;
        }
    }

    return consumed;
}

void legic_scene_scan_on_exit(void* context) {
    LegicApp* app = context;

    if(app->scan_active) {
        nfc_scanner_stop(app->scanner);
        nfc_scanner_free(app->scanner);
        app->scanner = NULL;
        app->scan_active = false;
    }

    notification_message(app->notifications, &sequence_blink_stop);
    popup_reset(app->popup);
}
