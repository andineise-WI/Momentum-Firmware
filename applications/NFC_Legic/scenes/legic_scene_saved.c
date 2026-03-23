#include "../legic_app_i.h"
#include "../helpers/legic_file.h"

#define TAG "LegicSaved"

void legic_scene_saved_on_enter(void* context) {
    LegicApp* app = context;

    DialogsFileBrowserOptions browser_options;
    dialog_file_browser_set_basic_options(&browser_options, LEGIC_APP_EXTENSION, NULL);
    browser_options.base_path = LEGIC_APP_FOLDER;
    browser_options.hide_ext = true;

    if(dialog_file_browser_show(app->dialogs, app->file_path, app->file_path, &browser_options)) {
        if(legic_file_load(app, furi_string_get_cstr(app->file_path))) {
            app->card_loaded = true;
            scene_manager_next_scene(app->scene_manager, LegicSceneSavedInfo);
        } else {
            scene_manager_previous_scene(app->scene_manager);
        }
    } else {
        scene_manager_previous_scene(app->scene_manager);
    }
}

bool legic_scene_saved_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void legic_scene_saved_on_exit(void* context) {
    UNUSED(context);
}
