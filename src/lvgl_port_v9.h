#ifndef LVGL_PORT_V9_H
#define LVGL_PORT_V9_H

#include <lvgl.h>
#include <ESP_Panel_Library.h>

#define BYTE_PER_PIXEL (LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_RGB888))
/**
 * LVGL timer handle task related parameters, can be adjusted by users
 *
 */
#define LVGL_PORT_TASK_MAX_DELAY_MS (500)    // The maximum delay of the LVGL timer task, in milliseconds
#define LVGL_PORT_TASK_MIN_DELAY_MS (2)      // The minimum delay of the LVGL timer task, in milliseconds
#define LVGL_PORT_TASK_STACK_SIZE (6 * 1024) // The stack size of the LVGL timer task, in bytes
#define LVGL_PORT_TASK_PRIORITY (2)          // The priority of the LVGL timer task
#define LVGL_PORT_TASK_CORE (-1)             // The core of the LVGL timer task, `-1` means the don't specify the core

/**********************
 * GLOBAL PROTOTYPES
 **********************/
/* Initialize low level display driver */
void lv_port_disp_init(ESP_PanelLcd *lcd);

/* Enable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_enable_update(void);

/* Disable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_disable_update(void);

bool lvgl_port_lock(int timeout_ms);

bool lvgl_port_unlock(void);

#endif