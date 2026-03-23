#include "../legic_app_i.h"
#include "../helpers/legic_worker.h"
#include "../helpers/legic_file.h"

#define TAG "LegicRead"

static void legic_scene_read_poller_callback(LegicWorkerEvent event, void* context) {
    furi_assert(context);
    LegicApp* app = context;

    if(event == LegicWorkerEventReadDone) {
        view_dispatcher_send_custom_event(app->view_dispatcher, LegicCustomEventReadDone);
    } else if(event == LegicWorkerEventFail) {
        view_dispatcher_send_custom_event(app->view_dispatcher, LegicCustomEventReadFail);
    }
}

void legic_scene_read_on_enter(void* context) {
    LegicApp* app = context;

    popup_set_header(app->popup, "Reading...", 64, 20, AlignCenter, AlignTop);
    popup_set_text(
        app->popup, "Hold LEGIC card\nto Flipper's back", 64, 35, AlignCenter, AlignTop);

    view_dispatcher_switch_to_view(app->view_dispatcher, LegicViewPopup);

    notification_message(app->notifications, &sequence_blink_start_cyan);

    legic_worker_start_read(app, legic_scene_read_poller_callback, app);
}

bool legic_scene_read_on_event(void* context, SceneManagerEvent event) {
    LegicApp* app = context;
    bool consumed = false;

    if(event.type == SceneManagerEventTypeCustom) {
        if(event.event == LegicCustomEventReadDone) {
            notification_message(app->notifications, &sequence_success);

            // Auto-save the dump
            legic_file_save(app);

            app->card_loaded = true;
            scene_manager_next_scene(app->scene_manager, LegicSceneCardInfo);
            consumed = true;
        } else if(event.event == LegicCustomEventReadFail) {
            notification_message(app->notifications, &sequence_error);

            popup_set_header(app->popup, "Read Failed!", 64, 32, AlignCenter, AlignCenter);
            popup_set_text(
                app->popup,
                "Card not found or\nnot a LEGIC card",
                64,
                50,
                AlignCenter,
                AlignTop);
            consumed = true;
        }
    }

    return consumed;
}

void legic_scene_read_on_exit(void* context) {
    LegicApp* app = context;

    legic_worker_stop(app);
    notification_message(app->notifications, &sequence_blink_stop);
    popup_reset(app->popup);
}
