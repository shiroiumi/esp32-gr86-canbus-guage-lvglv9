#include <Arduino.h>
#include <ESP_Panel_Library.h>
#include <lvgl.h>
#include <lvgl_port_v9.h>

#define LVGL_PORT_BUFFER_NUM_MAX (2)

static const char *TAG = "lvgl_port";
static SemaphoreHandle_t lvgl_mux = nullptr; // LVGL mutex
static TaskHandle_t lvgl_task_handle = nullptr;

static void flush_callback(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map);

static void lvgl_port_task(void *arg)
{
    ESP_LOGD(TAG, "Starting LVGL task");

    uint32_t task_delay_ms = LVGL_PORT_TASK_MAX_DELAY_MS;
    while (1)
    {
        if (lvgl_port_lock(-1))
        {
            task_delay_ms = lv_timer_handler();
            lvgl_port_unlock();
        }
        if (task_delay_ms > LVGL_PORT_TASK_MAX_DELAY_MS)
        {
            task_delay_ms = LVGL_PORT_TASK_MAX_DELAY_MS;
        }
        else if (task_delay_ms < LVGL_PORT_TASK_MIN_DELAY_MS)
        {
            task_delay_ms = LVGL_PORT_TASK_MIN_DELAY_MS;
        }
        vTaskDelay(pdMS_TO_TICKS(task_delay_ms));
    }
};

IRAM_ATTR bool onRefreshFinishCallback(void *user_data)
{
    lv_disp_flush_ready((lv_display_t *)user_data);

    return false;
}

void lv_port_disp_init(ESP_PanelLcd *lcd)
{
    lv_init();

    ESP_LOGD(TAG, "Create mutex for LVGL");
    lvgl_mux = xSemaphoreCreateRecursiveMutex();

    ESP_LOGD(TAG, "Create LVGL task");
    BaseType_t core_id = (LVGL_PORT_TASK_CORE < 0) ? tskNO_AFFINITY : LVGL_PORT_TASK_CORE;
    BaseType_t ret = xTaskCreatePinnedToCore(lvgl_port_task, "lvgl", LVGL_PORT_TASK_STACK_SIZE, NULL,
                                             LVGL_PORT_TASK_PRIORITY, &lvgl_task_handle, core_id);

    /*------------------------------------
     * Create a display and set a flush_cb
     * -----------------------------------*/
    Serial.println("Creating Display");
    ESP_LOGD(TAG, "Create Display");
    lv_display_t *disp = lv_display_create(ESP_PANEL_LCD_WIDTH, ESP_PANEL_LCD_HEIGHT);
    lv_display_set_user_data(disp, lcd);
    lv_display_set_flush_cb(disp, flush_callback);

    ESP_LOGD(TAG, "Assign Buffer");
    LV_ATTRIBUTE_MEM_ALIGN
    static uint8_t buf_2_1[ESP_PANEL_LCD_WIDTH * 40 * BYTE_PER_PIXEL];

    LV_ATTRIBUTE_MEM_ALIGN
    static uint8_t buf_2_2[ESP_PANEL_LCD_WIDTH * 40 * BYTE_PER_PIXEL];
    lv_display_set_buffers(disp, buf_2_1, buf_2_2, sizeof(buf_2_1), LV_DISPLAY_RENDER_MODE_PARTIAL);

    lcd->attachRefreshFinishCallback(onRefreshFinishCallback, (void *)disp);
}

void flush_callback(lv_display_t *display, const lv_area_t *area, uint8_t *px_map)
{
    ESP_PanelLcd *lcd = (ESP_PanelLcd *)lv_display_get_user_data(display);
    const int offsetx1 = area->x1;
    const int offsetx2 = area->x2;
    const int offsety1 = area->y1;
    const int offsety2 = area->y2;
    const int width = offsetx2 - offsetx1 + 1;
    const int height = offsety2 - offsety1 + 1;

    ESP_LOGD(TAG, "%x, %x, %x", px_map[0], px_map[1], px_map[2]);
    // Reverse the red and blue channels in the px_map
    for (int i = 0; i < width * height * 3; i += 3)
    {
        uint8_t r = (px_map[i] >> 2) << 2;     // Truncate the least significant 2 bits and shift to high bits
        uint8_t g = (px_map[i + 1] >> 2) << 2; // Truncate the least significant 2 bits and shift to high bits
        uint8_t b = (px_map[i + 2] >> 2) << 2; // Truncate the least significant 2 bits and shift to high bits

        // Swap the red and blue channels
        px_map[i] = b;
        px_map[i + 1] = g;
        px_map[i + 2] = r;
        // Serial.printf("0x%hhX, 0x%hhX, 0x%hhX |", px_map[i], px_map[i + 1], px_map[i + 2]);
    }

    lcd->drawBitmap(offsetx1, offsety1, offsetx2 - offsetx1 + 1, offsety2 - offsety1 + 1, px_map);

    // lv_disp_flush_ready(display);
}

static void update_callback(lv_display_t *disp)
{
    ESP_PanelLcd *lcd = (ESP_PanelLcd *)lv_display_get_user_data(disp);
    static bool disp_init_mirror_x = lcd->getMirrorXFlag();
    static bool disp_init_mirror_y = lcd->getMirrorYFlag();
    static bool disp_init_swap_xy = lcd->getSwapXYFlag();

    switch (lv_display_get_rotation(disp))
    {
    case LV_DISPLAY_ROTATION_0:
        lcd->swapXY(disp_init_swap_xy);
        lcd->mirrorX(disp_init_mirror_x);
        lcd->mirrorY(disp_init_mirror_y);
        break;
    case LV_DISPLAY_ROTATION_90:
        lcd->swapXY(!disp_init_swap_xy);
        lcd->mirrorX(disp_init_mirror_x);
        lcd->mirrorY(!disp_init_mirror_y);
        break;
    case LV_DISPLAY_ROTATION_180:
        lcd->swapXY(disp_init_swap_xy);
        lcd->mirrorX(!disp_init_mirror_x);
        lcd->mirrorY(!disp_init_mirror_y);
        break;
    case LV_DISPLAY_ROTATION_270:
        lcd->swapXY(!disp_init_swap_xy);
        lcd->mirrorX(!disp_init_mirror_x);
        lcd->mirrorY(disp_init_mirror_y);
        break;
    }

    ESP_LOGD(TAG, "Update display rotation to %d", drv->rotated);
    ESP_LOGD(TAG, "Current mirror x: %d, mirror y: %d, swap xy: %d", lcd->getMirrorXFlag(), lcd->getMirrorYFlag(), lcd->getSwapXYFlag());
}

void rounder_callback(lv_display_t *disp, lv_area_t *area)
{
    ESP_PanelLcd *lcd = (ESP_PanelLcd *)lv_display_get_user_data(disp);
    uint16_t x1 = area->x1;
    uint16_t x2 = area->x2;
    uint16_t y1 = area->y1;
    uint16_t y2 = area->y2;

    uint8_t x_align = lcd->getXCoordAlign();
    if (x_align > 1)
    {
        // round the start of coordinate down to the nearest (x_align * M) number
        area->x1 = (x1 / x_align) * x_align;
        // round the end of coordinate down to the nearest (x_align * (N + 1) - 1) number
        area->x2 = ((x2 + x_align - 1) / x_align + 1) * x_align - 1;
    }

    uint8_t y_align = lcd->getYCoordAlign();
    if (y_align > 1)
    {
        // round the start of coordinate down to the nearest (y_align * M) number
        area->y1 = (y1 / y_align) * y_align;
        // round the end of coordinate down to the nearest (y_align * (N + 1) - 1) number
        area->y2 = ((y2 + y_align - 1) / y_align + 1) * y_align - 1;
    }
}

bool lvgl_port_lock(int timeout_ms)
{
    ESP_PANEL_CHECK_NULL_RET(lvgl_mux, false, "LVGL mutex is not initialized");

    const TickType_t timeout_ticks = (timeout_ms < 0) ? portMAX_DELAY : pdMS_TO_TICKS(timeout_ms);
    return (xSemaphoreTakeRecursive(lvgl_mux, timeout_ticks) == pdTRUE);
}

bool lvgl_port_unlock(void)
{
    ESP_PANEL_CHECK_NULL_RET(lvgl_mux, false, "LVGL mutex is not initialized");

    xSemaphoreGiveRecursive(lvgl_mux);

    return true;
}
