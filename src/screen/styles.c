#include "styles.h"
#include "images.h"
#include "fonts.h"

//
// Style: Temp Guage
//

void init_style_temp_guage_INDICATOR_DEFAULT(lv_style_t *style) {
    lv_style_set_length(style, 10);
};

lv_style_t *get_style_temp_guage_INDICATOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_temp_guage_INDICATOR_DEFAULT(style);
    }
    return style;
};

void init_style_temp_guage_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_align(style, LV_ALIGN_CENTER);
    lv_style_set_text_color(style, lv_color_hex(0xff212121));
    lv_style_set_text_opa(style, 255);
    lv_style_set_text_font(style, &lv_font_montserrat_24);
};

lv_style_t *get_style_temp_guage_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_temp_guage_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_temp_guage_ITEMS_DEFAULT(lv_style_t *style) {
    lv_style_set_length(style, 5);
};

lv_style_t *get_style_temp_guage_ITEMS_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_temp_guage_ITEMS_DEFAULT(style);
    }
    return style;
};

void add_style_temp_guage(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_temp_guage_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_temp_guage_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_temp_guage_ITEMS_DEFAULT(), LV_PART_ITEMS | LV_STATE_DEFAULT);
};

void remove_style_temp_guage(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_temp_guage_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_temp_guage_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_temp_guage_ITEMS_DEFAULT(), LV_PART_ITEMS | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_temp_guage,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_temp_guage,
    };
    remove_style_funcs[styleIndex](obj);
}

