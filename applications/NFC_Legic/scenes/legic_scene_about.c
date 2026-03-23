#include "../legic_app_i.h"

void legic_scene_about_on_enter(void* context) {
    LegicApp* app = context;
    Widget* widget = app->widget;

    widget_add_string_element(
        widget, 64, 2, AlignCenter, AlignTop, FontPrimary, "LEGIC Reader v0.1");

    widget_add_string_multiline_element(
        widget,
        0,
        16,
        AlignLeft,
        AlignTop,
        FontSecondary,
        "NFC app for LEGIC advant\n"
        "cards (ISO14443A/ISO15693).\n"
        "\n"
        "Features:\n"
        "- Scan & identify cards\n"
        "- Read/dump public data\n"
        "- Balance display\n"
        "- Write/restore dumps\n"
        "\n"
        "Note: Protected segments\n"
        "require a LEGIC SM module.");

    view_dispatcher_switch_to_view(app->view_dispatcher, LegicViewWidget);
}

bool legic_scene_about_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void legic_scene_about_on_exit(void* context) {
    LegicApp* app = context;
    widget_reset(app->widget);
}
