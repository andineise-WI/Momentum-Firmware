#include "legic_app_i.h"

#include <furi_hal.h>

#define TAG "LegicApp"

static bool legic_app_custom_event_callback(void* context, uint32_t event) {
    furi_assert(context);
    LegicApp* app = context;
    return scene_manager_handle_custom_event(app->scene_manager, event);
}

static bool legic_app_back_event_callback(void* context) {
    furi_assert(context);
    LegicApp* app = context;
    return scene_manager_handle_back_event(app->scene_manager);
}

LegicApp* legic_app_alloc(void) {
    LegicApp* app = malloc(sizeof(LegicApp));

    app->gui = furi_record_open(RECORD_GUI);
    app->notifications = furi_record_open(RECORD_NOTIFICATION);
    app->dialogs = furi_record_open(RECORD_DIALOGS);
    app->storage = furi_record_open(RECORD_STORAGE);

    app->view_dispatcher = view_dispatcher_alloc();
    app->scene_manager = scene_manager_alloc(&legic_scene_handlers, app);
    view_dispatcher_set_event_callback_context(app->view_dispatcher, app);
    view_dispatcher_set_custom_event_callback(
        app->view_dispatcher, legic_app_custom_event_callback);
    view_dispatcher_set_navigation_event_callback(
        app->view_dispatcher, legic_app_back_event_callback);

    // Submenu
    app->submenu = submenu_alloc();
    view_dispatcher_add_view(
        app->view_dispatcher, LegicViewMenu, submenu_get_view(app->submenu));

    // Popup
    app->popup = popup_alloc();
    view_dispatcher_add_view(app->view_dispatcher, LegicViewPopup, popup_get_view(app->popup));

    // Loading
    app->loading = loading_alloc();
    view_dispatcher_add_view(
        app->view_dispatcher, LegicViewLoading, loading_get_view(app->loading));

    // Widget
    app->widget = widget_alloc();
    view_dispatcher_add_view(
        app->view_dispatcher, LegicViewWidget, widget_get_view(app->widget));

    // TextBox
    app->text_box = text_box_alloc();
    view_dispatcher_add_view(
        app->view_dispatcher, LegicViewTextBox, text_box_get_view(app->text_box));
    app->text_box_store = furi_string_alloc();

    // DialogEx
    app->dialog_ex = dialog_ex_alloc();
    view_dispatcher_add_view(
        app->view_dispatcher, LegicViewDialogEx, dialog_ex_get_view(app->dialog_ex));

    // ByteInput
    app->byte_input = byte_input_alloc();
    view_dispatcher_add_view(
        app->view_dispatcher, LegicViewByteInput, byte_input_get_view(app->byte_input));

    // NFC
    app->nfc = nfc_alloc();

    // Strings
    app->file_path = furi_string_alloc_set(LEGIC_APP_FOLDER);
    app->file_name = furi_string_alloc();

    // Ensure storage dir exists
    storage_simply_mkdir(app->storage, LEGIC_APP_FOLDER);

    // State
    app->card_loaded = false;
    app->scan_active = false;
    memset(&app->card_data, 0, sizeof(LegicCardData));

    return app;
}

void legic_app_free(LegicApp* app) {
    furi_assert(app);

    // NFC
    nfc_free(app->nfc);

    // Views
    view_dispatcher_remove_view(app->view_dispatcher, LegicViewMenu);
    view_dispatcher_remove_view(app->view_dispatcher, LegicViewPopup);
    view_dispatcher_remove_view(app->view_dispatcher, LegicViewLoading);
    view_dispatcher_remove_view(app->view_dispatcher, LegicViewWidget);
    view_dispatcher_remove_view(app->view_dispatcher, LegicViewTextBox);
    view_dispatcher_remove_view(app->view_dispatcher, LegicViewDialogEx);
    view_dispatcher_remove_view(app->view_dispatcher, LegicViewByteInput);

    submenu_free(app->submenu);
    popup_free(app->popup);
    loading_free(app->loading);
    widget_free(app->widget);
    text_box_free(app->text_box);
    dialog_ex_free(app->dialog_ex);
    byte_input_free(app->byte_input);

    furi_string_free(app->text_box_store);
    furi_string_free(app->file_path);
    furi_string_free(app->file_name);

    scene_manager_free(app->scene_manager);
    view_dispatcher_free(app->view_dispatcher);

    furi_record_close(RECORD_GUI);
    furi_record_close(RECORD_NOTIFICATION);
    furi_record_close(RECORD_DIALOGS);
    furi_record_close(RECORD_STORAGE);

    free(app);
}

int32_t legic_app_entry(void* p) {
    UNUSED(p);

    LegicApp* app = legic_app_alloc();

    view_dispatcher_attach_to_gui(app->view_dispatcher, app->gui, ViewDispatcherTypeFullscreen);
    scene_manager_next_scene(app->scene_manager, LegicSceneMainMenu);
    view_dispatcher_run(app->view_dispatcher);

    legic_app_free(app);
    return 0;
}
