#pragma once

typedef enum {
    LegicSceneMainMenu,
    LegicSceneScan,
    LegicSceneCardInfo,
    LegicSceneRead,
    LegicSceneBalance,
    LegicSceneWrite,
    LegicSceneSaved,
    LegicSceneSavedInfo,
    LegicSceneAbout,
    LegicSceneNum,
} LegicScene;

extern const SceneManagerHandlers legic_scene_handlers;
