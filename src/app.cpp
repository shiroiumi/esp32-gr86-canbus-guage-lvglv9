#include <Arduino.h>
#include "lvgl_port_v9.h"
#include <ESP_Panel_Library.h>

lv_obj_t *needle_line;

static void set_needle_line_value(void *obj, int32_t v)
{
    lv_scale_set_line_needle_value((lv_obj_t *)obj, needle_line, 60, v);
}

void lv_example_scale_3(void)
{
    lv_obj_t *scale_line = lv_scale_create(lv_screen_active());

    lv_obj_set_size(scale_line, 360, 360);
    lv_scale_set_mode(scale_line, LV_SCALE_MODE_ROUND_INNER);
    lv_obj_set_style_bg_opa(scale_line, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(scale_line, lv_palette_lighten(LV_PALETTE_RED, 5), 0);
    lv_obj_set_style_radius(scale_line, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(scale_line, true, 0);
    lv_obj_align(scale_line, LV_ALIGN_CENTER, 0, 0);

    lv_scale_set_label_show(scale_line, true);

    lv_scale_set_total_tick_count(scale_line, 31);
    lv_scale_set_major_tick_every(scale_line, 5);

    lv_obj_set_style_length(scale_line, 5, LV_PART_ITEMS);
    lv_obj_set_style_length(scale_line, 10, LV_PART_INDICATOR);
    lv_scale_set_range(scale_line, 10, 40);

    lv_scale_set_angle_range(scale_line, 270);
    lv_scale_set_rotation(scale_line, 135);

    needle_line = lv_line_create(scale_line);

    lv_obj_set_style_line_width(needle_line, 6, LV_PART_MAIN);
    lv_obj_set_style_line_rounded(needle_line, true, LV_PART_MAIN);

    lv_anim_t anim_scale_line;
    lv_anim_init(&anim_scale_line);
    lv_anim_set_var(&anim_scale_line, scale_line);
    lv_anim_set_exec_cb(&anim_scale_line, set_needle_line_value);
    lv_anim_set_duration(&anim_scale_line, 1000);
    lv_anim_set_repeat_count(&anim_scale_line, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_playback_duration(&anim_scale_line, 1000);
    lv_anim_set_values(&anim_scale_line, 10, 40);
    lv_anim_start(&anim_scale_line);
}

void setup()
{
    Serial.begin(115200);
    delay(5000);
    Serial.println("Initialize panel device");

    ESP_PanelBus_SPI *panel_bus = new ESP_PanelBus_SPI(ESP_PANEL_LCD_SPI_IO_CS, ESP_PANEL_LCD_SPI_IO_DC,
                                                       ESP_PANEL_LCD_SPI_IO_SCK, ESP_PANEL_LCD_SPI_IO_MOSI,
                                                       ESP_PANEL_LCD_SPI_IO_MISO);
    panel_bus->configSpiFreqHz(ESP_PANEL_LCD_SPI_CLK_HZ);
    panel_bus->begin();
    ESP_PanelLcd *lcd = new ESP_PanelLcd_ST77916(panel_bus, ESP_PANEL_LCD_COLOR_BITS, ESP_PANEL_LCD_IO_RST);
    lcd->init();
    lcd->reset();
    lcd->begin();
    lcd->displayOn();
    // Serial.println("Init LVGL");
    lv_port_disp_init(lcd);
    // /* Lock the mutex due to the LVGL APIs are not thread-safe */
    lvgl_port_lock(-1);
    // // // Create a style for the background
    static lv_style_t style_bg;
    lv_style_init(&style_bg);
    lv_style_set_bg_color(&style_bg, lv_color_hex3(0x00F));
    lv_style_set_bg_opa(&style_bg, LV_OPA_COVER);
    lv_obj_t *screen = lv_scr_act();
    lv_obj_add_style(screen, &style_bg, 0);
    lv_example_scale_3();
    lv_tick_inc(100);
    lvgl_port_unlock();
}

void loop()
{
    lv_task_handler();
    vTaskDelay(pdMS_TO_TICKS(10)); // Adjust the delay as necessary
}