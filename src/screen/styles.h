#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C"
{
#endif

    // Style: Guage
    lv_style_t *get_style_guage_INDICATOR_DEFAULT();
    lv_style_t *get_style_guage_MAIN_DEFAULT();
    lv_style_t *get_style_guage_ITEMS_DEFAULT();
    void add_style_guage(lv_obj_t *obj);
    void remove_style_guage(lv_obj_t *obj);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/