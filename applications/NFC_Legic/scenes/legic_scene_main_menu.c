#include "../legic_app_i.h"

enum {
    LegicMainMenuScan,
    LegicMainMenuRead,
    LegicMainMenuBalance,
    LegicMainMenuWrite,
    LegicMainMenuSaved,
    LegicMainMenuAbout,
};

static void legic_scene_main_menu_submenu_callback(void* context, uint32_t index) {
    furi_assert(context);
    LegicApp* app = context;
    view_dispatcher_send_custom_event(app->view_dispatcher, index);
}

void legic_scene_main_menu_on_enter(void* context) {
    LegicApp* app = context;
    Submenu* submenu = app->submenu;

    submenu_set_header(submenu, "LEGIC Reader");

    submenu_add_item(submenu, "Scan Card", LegicMainMenuScan, legic_scene_main_menu_submenu_callback, app);
    submenu_add_item(submenu, "Read/Dump", LegicMainMenuRead, legic_scene_main_menu_submenu_callback, app);
    submenu_add_item(submenu, "Balance", LegicMainMenuBalance, legic_scene_main_menu_submenu_callback, app);
    submenu_add_item(submenu, "Write/Restore", LegicMainMenuWrite, legic_scene_main_menu_submenu_callback, app);
    submenu_add_item(submenu, "Saved", LegicMainMenuSaved, legic_scene_main_menu_submenu_callback, app);
    submenu_add_item(submenu, "About", LegicMainMenuAbout, legic_scene_main_menu_submenu_callback, app);

    submenu_set_selected_item(
        submenu,
        scene_manager_get_scene_state(app->scene_manager, LegicSceneMainMenu));

    view_dispatcher_switch_to_view(app->view_dispatcher, LegicViewMenu);
}

bool legic_scene_main_menu_on_event(void* context, SceneManagerEvent event) {
    LegicApp* app = context;
    bool consumed = false;

    if(event.type == SceneManagerEventTypeCustom) {
        scene_manager_set_scene_state(app->scene_manager, LegicSceneMainMenu, event.event);
        consumed = true;

        switch(event.event) {
        case LegicMainMenuScan:
            scene_manager_next_scene(app->scene_manager, LegicSceneScan);
            break;
        case LegicMainMenuRead:
            scene_manager_next_scene(app->scene_manager, LegicSceneRead);
            break;
        case LegicMainMenuBalance:
            scene_manager_next_scene(app->scene_manager, LegicSceneBalance);
            break;
        case LegicMainMenuWrite:
            scene_manager_next_scene(app->scene_manager, LegicSceneWrite);
            break;
        case LegicMainMenuSaved:
            scene_manager_next_scene(app->scene_manager, LegicSceneSaved);
            break;
        case LegicMainMenuAbout:
            scene_manager_next_scene(app->scene_manager, LegicSceneAbout);
            break;
        default:
            consumed = false;
            break;
        }
    }

    return consumed;
}

void legic_scene_main_menu_on_exit(void* context) {
    LegicApp* app = context;
    submenu_reset(app->submenu);
}
