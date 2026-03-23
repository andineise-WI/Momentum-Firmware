#include "../legic_app_i.h"

// Scene on_enter handlers declaration
void legic_scene_main_menu_on_enter(void* context);
void legic_scene_scan_on_enter(void* context);
void legic_scene_card_info_on_enter(void* context);
void legic_scene_read_on_enter(void* context);
void legic_scene_balance_on_enter(void* context);
void legic_scene_write_on_enter(void* context);
void legic_scene_saved_on_enter(void* context);
void legic_scene_saved_info_on_enter(void* context);
void legic_scene_about_on_enter(void* context);

// Scene on_event handlers declaration
bool legic_scene_main_menu_on_event(void* context, SceneManagerEvent event);
bool legic_scene_scan_on_event(void* context, SceneManagerEvent event);
bool legic_scene_card_info_on_event(void* context, SceneManagerEvent event);
bool legic_scene_read_on_event(void* context, SceneManagerEvent event);
bool legic_scene_balance_on_event(void* context, SceneManagerEvent event);
bool legic_scene_write_on_event(void* context, SceneManagerEvent event);
bool legic_scene_saved_on_event(void* context, SceneManagerEvent event);
bool legic_scene_saved_info_on_event(void* context, SceneManagerEvent event);
bool legic_scene_about_on_event(void* context, SceneManagerEvent event);

// Scene on_exit handlers declaration
void legic_scene_main_menu_on_exit(void* context);
void legic_scene_scan_on_exit(void* context);
void legic_scene_card_info_on_exit(void* context);
void legic_scene_read_on_exit(void* context);
void legic_scene_balance_on_exit(void* context);
void legic_scene_write_on_exit(void* context);
void legic_scene_saved_on_exit(void* context);
void legic_scene_saved_info_on_exit(void* context);
void legic_scene_about_on_exit(void* context);

static const AppSceneOnEnterCallback legic_scene_on_enter_handlers[] = {
    [LegicSceneMainMenu] = legic_scene_main_menu_on_enter,
    [LegicSceneScan] = legic_scene_scan_on_enter,
    [LegicSceneCardInfo] = legic_scene_card_info_on_enter,
    [LegicSceneRead] = legic_scene_read_on_enter,
    [LegicSceneBalance] = legic_scene_balance_on_enter,
    [LegicSceneWrite] = legic_scene_write_on_enter,
    [LegicSceneSaved] = legic_scene_saved_on_enter,
    [LegicSceneSavedInfo] = legic_scene_saved_info_on_enter,
    [LegicSceneAbout] = legic_scene_about_on_enter,
};

static const AppSceneOnEventCallback legic_scene_on_event_handlers[] = {
    [LegicSceneMainMenu] = legic_scene_main_menu_on_event,
    [LegicSceneScan] = legic_scene_scan_on_event,
    [LegicSceneCardInfo] = legic_scene_card_info_on_event,
    [LegicSceneRead] = legic_scene_read_on_event,
    [LegicSceneBalance] = legic_scene_balance_on_event,
    [LegicSceneWrite] = legic_scene_write_on_event,
    [LegicSceneSaved] = legic_scene_saved_on_event,
    [LegicSceneSavedInfo] = legic_scene_saved_info_on_event,
    [LegicSceneAbout] = legic_scene_about_on_event,
};

static const AppSceneOnExitCallback legic_scene_on_exit_handlers[] = {
    [LegicSceneMainMenu] = legic_scene_main_menu_on_exit,
    [LegicSceneScan] = legic_scene_scan_on_exit,
    [LegicSceneCardInfo] = legic_scene_card_info_on_exit,
    [LegicSceneRead] = legic_scene_read_on_exit,
    [LegicSceneBalance] = legic_scene_balance_on_exit,
    [LegicSceneWrite] = legic_scene_write_on_exit,
    [LegicSceneSaved] = legic_scene_saved_on_exit,
    [LegicSceneSavedInfo] = legic_scene_saved_info_on_exit,
    [LegicSceneAbout] = legic_scene_about_on_exit,
};

const SceneManagerHandlers legic_scene_handlers = {
    .on_enter_handlers = legic_scene_on_enter_handlers,
    .on_event_handlers = legic_scene_on_event_handlers,
    .on_exit_handlers = legic_scene_on_exit_handlers,
    .scene_num = LegicSceneNum,
};
