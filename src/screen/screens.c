#include <string.h>
#include <stdio.h>
#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"
#include <lvgl.h>
#include "control/display_control.h"
#include "../../.pio/libdeps/ESP-LCD/lvgl/src/lvgl_private.h"
#include "log.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;
GuageMode lastSeen;

static void draw_event_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_draw_task_t *draw_task = lv_event_get_draw_task(e);
    lv_draw_dsc_base_t *base_dsc = lv_draw_task_get_draw_dsc(draw_task);
    lv_draw_label_dsc_t *label_draw_dsc = lv_draw_task_get_label_dsc(draw_task);
    if (base_dsc->part == LV_PART_INDICATOR)
    {
        if (label_draw_dsc)
        {
            if (get_guage_mode() == RPM)
            {
                /*Free the previously allocated text if needed*/
                if (label_draw_dsc->text_local)
                    lv_free((void *)label_draw_dsc->text);

                /*Malloc the text and set text_local as 1 to make LVGL automatically free the text.
                 * (Local texts are malloc'd internally by LVGL. Mimic this behavior here too)*/
                char tmp_buffer[20] = {0}; /* Big enough buffer */
                lv_snprintf(tmp_buffer, sizeof(tmp_buffer), "%d", base_dsc->id2 / 1000);
                label_draw_dsc->text = lv_strdup(tmp_buffer);
                label_draw_dsc->text_local = 1;

                lv_point_t size;
                lv_text_get_size(&size, label_draw_dsc->text, label_draw_dsc->font, 0, 0, 1000, LV_TEXT_FLAG_NONE);
                int32_t new_w = size.x;
                int32_t old_w = lv_area_get_width(&draw_task->area);

                /* Distribute the new size equally on both sides */
                draw_task->area.x1 -= (new_w - old_w) / 2;
                draw_task->area.x2 += ((new_w - old_w) + 1) / 2; /* +1 for rounding */
            }
            else
            {
                /*Free the previously allocated text if needed*/
                if (label_draw_dsc->text_local)
                    lv_free((void *)label_draw_dsc->text);

                /*Malloc the text and set text_local as 1 to make LVGL automatically free the text.
                 * (Local texts are malloc'd internally by LVGL. Mimic this behavior here too)*/
                char tmp_buffer[20] = {0}; /* Big enough buffer */
                lv_snprintf(tmp_buffer, sizeof(tmp_buffer), "%d", base_dsc->id2);
                label_draw_dsc->text = lv_strdup(tmp_buffer);
                label_draw_dsc->text_local = 1;

                lv_point_t size;
                lv_text_get_size(&size, label_draw_dsc->text, label_draw_dsc->font, 0, 0, 1000, LV_TEXT_FLAG_NONE);
                int32_t new_w = size.x;
                int32_t old_w = lv_area_get_width(&draw_task->area);

                /* Distribute the new size equally on both sides */
                draw_task->area.x1 -= (new_w - old_w) / 2;
                draw_task->area.x2 += ((new_w - old_w) + 1) / 2; /* +1 for rounding */
            }
        }
    }
}

static void event_handler_cb_main_arc_value(lv_event_t *e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED)
    {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta)
        {
            int32_t value = lv_arc_get_value(ta);
            set_var_unit_value(value);
        }
    }
}

void create_screen_main()
{
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 360, 360);
    lv_obj_set_style_text_font(obj, &ui_font_excluded_58, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 360, 360);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_chart_create(parent_obj);
                    lv_obj_set_pos(obj, 92, 251);
                    lv_obj_set_size(obj, 145, 74);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // sub_unit_text
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.sub_unit_text = obj;
                    lv_obj_set_pos(obj, -89, 24);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &ui_font_excluded_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffdadada), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // text_value
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.text_value = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffdadada), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_excluded_58, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // arc_value
                    lv_obj_t *obj = lv_arc_create(parent_obj);
                    objects.arc_value = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 350, 350);
                    lv_arc_set_bg_start_angle(obj, 135);
                    lv_arc_set_bg_end_angle(obj, 45);
                    lv_obj_add_event_cb(obj, event_handler_cb_main_arc_value, LV_EVENT_ALL, 0);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_rounded(obj, false, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_opa(obj, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_color(obj, lv_color_hex(0xffdadada), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_rounded(obj, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 25, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_color(obj, lv_color_hex(0xffdadada), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
                }
                {
                    // guage_scale
                    lv_obj_t *obj = lv_scale_create(parent_obj);
                    objects.guage_scale = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 300, 300);
                    lv_scale_set_mode(obj, LV_SCALE_MODE_ROUND_INNER);
                    lv_scale_set_range(obj, 0, 9000);
                    lv_scale_set_total_tick_count(obj, 91);
                    lv_scale_set_major_tick_every(obj, 10);
                    lv_scale_set_label_show(obj, true);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_SCROLL_CHAIN_VER | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_WITH_ARROW | LV_OBJ_FLAG_SNAPPABLE);
                    add_style_guage(obj);
                    lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff9fd8ed), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_length(obj, 25, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_width(obj, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_color(obj, lv_color_hex(0xffdadada), LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_length(obj, 25, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_width(obj, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_color(obj, lv_color_hex(0xffdadada), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_rounded(obj, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffdadada), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_excluded_16, LV_PART_INDICATOR | LV_STATE_DEFAULT);

                    // red section
                    static lv_style_t section_minor_tick_style;
                    static lv_style_t section_label_style;
                    static lv_style_t section_main_line_style;

                    lv_style_init(&section_label_style);
                    lv_style_init(&section_minor_tick_style);
                    lv_style_init(&section_main_line_style);

                    /* Label style properties */
                    lv_style_set_text_font(&section_label_style, &ui_font_excluded_16);
                    lv_style_set_text_color(&section_label_style, lv_palette_darken(LV_PALETTE_RED, 3));

                    lv_style_set_line_color(&section_label_style, lv_palette_darken(LV_PALETTE_RED, 3));
                    lv_style_set_line_width(&section_label_style, 2); /*Tick width*/

                    lv_style_set_line_color(&section_minor_tick_style, lv_palette_lighten(LV_PALETTE_RED, 2));
                    lv_style_set_line_width(&section_minor_tick_style, 1); /*Tick width*/

                    /* Main line properties */
                    lv_style_set_arc_color(&section_main_line_style, lv_palette_darken(LV_PALETTE_RED, 3));
                    lv_style_set_arc_width(&section_main_line_style, 2); /*Tick width*/

                    /* Configure section styles */
                    lv_scale_section_t *section = lv_scale_add_section(objects.guage_scale);
                    lv_scale_section_set_range(section, 7500, 9000);
                    lv_scale_section_set_style(section, LV_PART_INDICATOR, &section_label_style);
                    lv_scale_section_set_style(section, LV_PART_ITEMS, &section_minor_tick_style);
                    lv_scale_section_set_style(section, LV_PART_MAIN, &section_main_line_style);

                    lv_obj_add_event(objects.guage_scale, draw_event_cb, LV_EVENT_DRAW_TASK_ADDED, NULL);
                    lv_obj_add_flag(objects.guage_scale, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);
                }
            }
        }
    }
}

void tick_screen_main()
{
    // static GuageMode lastSeen;
    // static bool screenChanged = false;
    // if (lastSeen != get_guage_mode())
    // {
    //     screenChanged = true;
    //     lastSeen = get_guage_mode();
    // }
    // else
    // {
    //     screenChanged = false;
    // }

    // if (screenChanged)
    // {

    //     lv_event_send(objects.guage_scale, LV_EVENT_DRAW_TASK_ADDED, NULL);
    // }
    {
        const char *new_val = get_var_unit();
        const char *cur_val = lv_label_get_text(objects.sub_unit_text);
        if (strcmp(new_val, cur_val) != 0)
        {
            tick_value_change_obj = objects.sub_unit_text;
            lv_label_set_text(objects.sub_unit_text, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_arc_min();
        int32_t cur_val = lv_arc_get_min_value(objects.arc_value);
        if (new_val != cur_val)
        {
            tick_value_change_obj = objects.arc_value;
            int16_t min = new_val;
            int16_t max = lv_arc_get_max_value(objects.arc_value);
            if (min < max)
            {
                lv_arc_set_range(objects.arc_value, min, max);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_arc_max();
        int32_t cur_val = lv_arc_get_max_value(objects.arc_value);
        if (new_val != cur_val)
        {
            tick_value_change_obj = objects.arc_value;
            int16_t min = lv_arc_get_min_value(objects.arc_value);
            int16_t max = new_val;
            if (min < max)
            {
                lv_arc_set_range(objects.arc_value, min, max);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_unit_value();
        int32_t cur_val = lv_arc_get_value(objects.arc_value);
        if (new_val != cur_val)
        {
            tick_value_change_obj = objects.arc_value;
            lv_arc_set_value(objects.arc_value, new_val);
            tick_value_change_obj = NULL;
        }
    }

    // Custom
    {
        char new_value[12];
        if (get_guage_mode() == OIL_TEMP)
        {
            snprintf(new_value, sizeof(new_value), "%d C", get_var_unit_value());
        }
        else
        {
            snprintf(new_value, sizeof(new_value), "%d", get_var_unit_value());
        }
        const char *cur_val = lv_label_get_text(objects.sub_unit_text);
        if (strcmp(new_value, cur_val) != 0)
        {
            tick_value_change_obj = objects.text_value;
            lv_label_set_text(objects.text_value, new_value);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_guage_min();
        int32_t cur_val = lv_scale_get_range_min_value(objects.guage_scale);
        if (new_val != cur_val)
        {
            tick_value_change_obj = objects.guage_scale;
            int16_t min = new_val;
            int16_t max = lv_scale_get_range_max_value(objects.guage_scale);
            if (min < max)
            {
                lv_scale_set_range(objects.guage_scale, min, max);
            }
            lv_scale_set_label_show(objects.guage_scale, true);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_guage_max();
        int32_t cur_val = lv_scale_get_range_max_value(objects.guage_scale);
        if (new_val != cur_val)
        {
            tick_value_change_obj = objects.guage_scale;
            int16_t min = lv_scale_get_range_min_value(objects.guage_scale);
            int16_t max = new_val;
            if (min < max)
            {
                lv_scale_set_range(objects.guage_scale, min, max);
            }
            lv_scale_set_label_show(objects.guage_scale, true);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_guage_ticks();
        int32_t cur_val = lv_scale_get_total_tick_count(objects.guage_scale);
        if (new_val != cur_val)
        {
            tick_value_change_obj = objects.guage_scale;
            lv_scale_set_total_tick_count(objects.guage_scale, new_val);
            lv_scale_set_label_show(objects.guage_scale, true);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_guage_major_ticks_every();
        int32_t cur_val = lv_scale_get_major_tick_every(objects.guage_scale);
        if (new_val != cur_val)
        {
            tick_value_change_obj = objects.guage_scale;
            lv_scale_set_major_tick_every(objects.guage_scale, new_val);
            lv_scale_set_label_show(objects.guage_scale, true);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screens()
{
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);

    create_screen_main();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};

void tick_screen(int screen_index)
{
    tick_screen_funcs[screen_index]();
}
