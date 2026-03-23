#include "../legic_app_i.h"
#include "../helpers/legic_worker.h"
#include "../helpers/legic_parser.h"

#define TAG "LegicBalance"

static void legic_scene_balance_poller_callback(LegicWorkerEvent event, void* context) {
    furi_assert(context);
    LegicApp* app = context;

    if(event == LegicWorkerEventReadDone) {
        view_dispatcher_send_custom_event(app->view_dispatcher, LegicCustomEventReadDone);
    } else if(event == LegicWorkerEventFail) {
        view_dispatcher_send_custom_event(app->view_dispatcher, LegicCustomEventReadFail);
    }
}

void legic_scene_balance_on_enter(void* context) {
    LegicApp* app = context;

    // If card is already loaded, show balance directly
    if(app->card_loaded && app->card_data.raw_data_len > 0) {
        Widget* widget = app->widget;

        widget_add_string_element(
            widget, 64, 2, AlignCenter, AlignTop, FontPrimary, "LEGIC Balance");

        if(legic_parser_find_value_field(&app->card_data)) {
            FuriString* balance_str = furi_string_alloc();
            int32_t balance = app->card_data.balance;
            furi_string_printf(
                balance_str, "Balance: %ld.%02ld", (long)(balance / 100), (long)(balance % 100));
            widget_add_string_element(
                widget,
                64,
                32,
                AlignCenter,
                AlignCenter,
                FontBigNumbers,
                furi_string_get_cstr(balance_str));
            furi_string_free(balance_str);
        } else {
            widget_add_string_element(
                widget,
                64,
                32,
                AlignCenter,
                AlignCenter,
                FontSecondary,
                "No value field found");
        }

        view_dispatcher_switch_to_view(app->view_dispatcher, LegicViewWidget);
    } else {
        // Need to read the card first
        popup_set_header(app->popup, "Reading Balance...", 64, 20, AlignCenter, AlignTop);
        popup_set_text(
            app->popup, "Hold LEGIC card\nto Flipper's back", 64, 35, AlignCenter, AlignTop);

        view_dispatcher_switch_to_view(app->view_dispatcher, LegicViewPopup);

        notification_message(app->notifications, &sequence_blink_start_cyan);

        legic_worker_start_read(app, legic_scene_balance_poller_callback, app);
    }
}

bool legic_scene_balance_on_event(void* context, SceneManagerEvent event) {
    LegicApp* app = context;
    bool consumed = false;

    if(event.type == SceneManagerEventTypeCustom) {
        if(event.event == LegicCustomEventReadDone) {
            notification_message(app->notifications, &sequence_success);

            // Now show balance
            Widget* widget = app->widget;
            widget_reset(widget);

            widget_add_string_element(
                widget, 64, 2, AlignCenter, AlignTop, FontPrimary, "LEGIC Balance");

            if(legic_parser_find_value_field(&app->card_data)) {
                FuriString* balance_str = furi_string_alloc();
                int32_t balance = app->card_data.balance;
                furi_string_printf(
                    balance_str,
                    "Balance: %ld.%02ld",
                    (long)(balance / 100),
                    (long)(balance % 100));
                widget_add_string_element(
                    widget,
                    64,
                    32,
                    AlignCenter,
                    AlignCenter,
                    FontBigNumbers,
                    furi_string_get_cstr(balance_str));
                furi_string_free(balance_str);
            } else {
                widget_add_string_element(
                    widget,
                    64,
                    32,
                    AlignCenter,
                    AlignCenter,
                    FontSecondary,
                    "No value field found");
            }

            view_dispatcher_switch_to_view(app->view_dispatcher, LegicViewWidget);
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

void legic_scene_balance_on_exit(void* context) {
    LegicApp* app = context;

    legic_worker_stop(app);
    notification_message(app->notifications, &sequence_blink_stop);
    popup_reset(app->popup);
    widget_reset(app->widget);
}
