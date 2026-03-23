#include "../legic_app_i.h"
#include "../helpers/legic_parser.h"

void legic_scene_card_info_on_enter(void* context) {
    LegicApp* app = context;
    Widget* widget = app->widget;
    LegicCardData* card = &app->card_data;

    widget_add_string_element(widget, 64, 2, AlignCenter, AlignTop, FontPrimary, "LEGIC Card Info");

    FuriString* info = furi_string_alloc();

    // UID
    furi_string_cat_printf(info, "UID: ");
    for(uint8_t i = 0; i < card->uid_len; i++) {
        furi_string_cat_printf(info, "%02X", card->uid[i]);
        if(i < card->uid_len - 1) furi_string_cat_printf(info, ":");
    }
    furi_string_cat_printf(info, "\n");

    // RF Standard
    furi_string_cat_printf(info, "RF: %s\n", legic_rf_std_name(card->rf_std));

    // FS Version
    furi_string_cat_printf(info, "FS: %s\n", legic_fs_version_name(card->fs_version));

    // Segments
    furi_string_cat_printf(info, "Segments: %d", card->segment_count);

    widget_add_string_multiline_element(
        widget, 0, 16, AlignLeft, AlignTop, FontSecondary, furi_string_get_cstr(info));

    furi_string_free(info);

    view_dispatcher_switch_to_view(app->view_dispatcher, LegicViewWidget);
}

bool legic_scene_card_info_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void legic_scene_card_info_on_exit(void* context) {
    LegicApp* app = context;
    widget_reset(app->widget);
}
