#include "../legic_app_i.h"
#include "../helpers/legic_worker.h"
#include "../helpers/legic_file.h"

#define TAG "LegicWrite"

static void legic_scene_write_poller_callback(LegicWorkerEvent event, void* context) {
    furi_assert(context);
    LegicApp* app = context;

    if(event == LegicWorkerEventWriteDone) {
        view_dispatcher_send_custom_event(app->view_dispatcher, LegicCustomEventWriteDone);
    } else if(event == LegicWorkerEventFail) {
        view_dispatcher_send_custom_event(app->view_dispatcher, LegicCustomEventWriteFail);
    }
}

void legic_scene_write_on_enter(void* context) {
    LegicApp* app = context;

    // First check if we have data loaded
    if(!app->card_loaded || app->card_data.raw_data_len == 0) {
        // Need to load a file first
        DialogsFileBrowserOptions browser_options;
        dialog_file_browser_set_basic_options(
            &browser_options, LEGIC_APP_EXTENSION, NULL);
        browser_options.base_path = LEGIC_APP_FOLDER;
        browser_options.hide_ext = true;

        if(dialog_file_browser_show(app->dialogs, app->file_path, app->file_path, &browser_options)) {
            if(legic_file_load(app, furi_string_get_cstr(app->file_path))) {
                app->card_loaded = true;
            }
        }

        if(!app->card_loaded) {
            scene_manager_previous_scene(app->scene_manager);
            return;
        }
    }

    popup_set_header(app->popup, "Writing...", 64, 20, AlignCenter, AlignTop);
    popup_set_text(
        app->popup, "Hold LEGIC card\nto Flipper's back", 64, 35, AlignCenter, AlignTop);

    view_dispatcher_switch_to_view(app->view_dispatcher, LegicViewPopup);

    notification_message(app->notifications, &sequence_blink_start_magenta);

    legic_worker_start_write(app, legic_scene_write_poller_callback, app);
}

bool legic_scene_write_on_event(void* context, SceneManagerEvent event) {
    LegicApp* app = context;
    bool consumed = false;

    if(event.type == SceneManagerEventTypeCustom) {
        if(event.event == LegicCustomEventWriteDone) {
            notification_message(app->notifications, &sequence_success);

            popup_set_header(app->popup, "Write Done!", 64, 32, AlignCenter, AlignCenter);
            popup_set_text(
                app->popup, "Data written\nsuccessfully", 64, 50, AlignCenter, AlignTop);
            popup_set_icon(app->popup, 0, 0, NULL);
            consumed = true;
        } else if(event.event == LegicCustomEventWriteFail) {
            notification_message(app->notifications, &sequence_error);

            popup_set_header(app->popup, "Write Failed!", 64, 32, AlignCenter, AlignCenter);
            popup_set_text(
                app->popup,
                "Card protected or\nnot in field",
                64,
                50,
                AlignCenter,
                AlignTop);
            popup_set_icon(app->popup, 0, 0, NULL);
            consumed = true;
        }
    }

    return consumed;
}

void legic_scene_write_on_exit(void* context) {
    LegicApp* app = context;

    legic_worker_stop(app);
    notification_message(app->notifications, &sequence_blink_stop);
    popup_reset(app->popup);
}
