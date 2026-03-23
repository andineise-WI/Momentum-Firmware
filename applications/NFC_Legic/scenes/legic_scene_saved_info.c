#include "../legic_app_i.h"
#include "../helpers/legic_parser.h"

void legic_scene_saved_info_on_enter(void* context) {
    LegicApp* app = context;
    LegicCardData* card = &app->card_data;

    FuriString* text = furi_string_alloc();

    // UID
    furi_string_cat_printf(text, "UID: ");
    for(uint8_t i = 0; i < card->uid_len; i++) {
        furi_string_cat_printf(text, "%02X", card->uid[i]);
        if(i < card->uid_len - 1) furi_string_cat_printf(text, ":");
    }
    furi_string_cat_printf(text, "\nRF: %s\n", legic_rf_std_name(card->rf_std));
    furi_string_cat_printf(text, "FS: %s\n", legic_fs_version_name(card->fs_version));
    furi_string_cat_printf(text, "Segments: %d\n", card->segment_count);
    furi_string_cat_printf(text, "Data: %d bytes\n", card->raw_data_len);

    // Hex dump (first 64 bytes)
    furi_string_cat_printf(text, "\nHex Dump:\n");
    uint16_t show_len = card->raw_data_len > 64 ? 64 : card->raw_data_len;
    for(uint16_t i = 0; i < show_len; i++) {
        furi_string_cat_printf(text, "%02X ", card->raw_data[i]);
        if((i + 1) % 8 == 0) furi_string_cat_printf(text, "\n");
    }
    if(card->raw_data_len > 64) {
        furi_string_cat_printf(text, "...");
    }

    furi_string_set(app->text_box_store, text);
    text_box_set_text(app->text_box, furi_string_get_cstr(app->text_box_store));
    text_box_set_font(app->text_box, TextBoxFontHex);

    furi_string_free(text);

    view_dispatcher_switch_to_view(app->view_dispatcher, LegicViewTextBox);
}

bool legic_scene_saved_info_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void legic_scene_saved_info_on_exit(void* context) {
    LegicApp* app = context;
    text_box_reset(app->text_box);
    furi_string_reset(app->text_box_store);
}
