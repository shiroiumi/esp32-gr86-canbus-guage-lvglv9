#include <Arduino.h>
#include "lvgl_port_v9.h"
#include <ESP_Panel_Library.h>
#include "screen/ui.h"
#include "screen/vars.h"
#include <driver/twai.h>
#include <driver/gpio.h>

ulong lastTick = 0;

void can_task(void *params)
{
    for (;;)
    {
        twai_message_t rx_frame;
        if (twai_receive(&rx_frame, pdMS_TO_TICKS(200)) == ESP_OK)
        {
            // Oil Temp
            if (rx_frame.identifier == 0x345)
            {
                // set_var_engine_temperature(rx_frame.data[3] - 40);
            }
            // RPM 16 bit offset 14 length
            if (rx_frame.identifier == 0x40)
            {
                set_var_engine_temperature(((rx_frame.data[3] << 8) | rx_frame.data[2]) & 0x3FFF);
            }
        }
    }
}

void setup_can_driver()
{
    twai_general_config_t general_config = {
        .mode = TWAI_MODE_NORMAL,
        .tx_io = (gpio_num_t)GPIO_NUM_16,
        .rx_io = (gpio_num_t)GPIO_NUM_17,
        .clkout_io = (gpio_num_t)TWAI_IO_UNUSED,
        .bus_off_io = (gpio_num_t)TWAI_IO_UNUSED,
        .tx_queue_len = 0,
        .rx_queue_len = 65,
        .alerts_enabled = TWAI_ALERT_ALL,
        .clkout_divider = 0};

    twai_timing_config_t timing_config = TWAI_TIMING_CONFIG_500KBITS();
    twai_filter_config_t filter_config = TWAI_FILTER_CONFIG_ACCEPT_ALL();

    esp_err_t error;
    error = twai_driver_install(&general_config, &timing_config, &filter_config);

    if (error == ESP_OK)
    {
        Serial.println("CAN DRIVER Installation OK!");
    }
    else
    {
        Serial.println("CAN DRIVER Installation Failed :(");
        return;
    }

    error = twai_start();

    if (error == ESP_OK)
    {
        Serial.println("CAN DRIVER STARTED!");
    }
    else
    {
        Serial.println("CAN DRIVER FAILED :(");
        return;
    }

    TaskHandle_t can_task_handler;
    xTaskCreatePinnedToCore(
        can_task,          /* Function to implement the task */
        "can_task",        /* Name of the task */
        10000,             /* Stack size in words */
        NULL,              /* Task input parameter */
        0,                 /* Priority of the task */
        &can_task_handler, /* Task handle. */
        0);                /* Core where the task should run */
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
    ui_init();
    lvgl_port_unlock();
    setup_can_driver();
    Serial.println("Connected to CANBUS!");
    lastTick = millis();
}

void loop()
{
    lvgl_port_lock(-1);
    ui_tick();
    lvgl_port_unlock();
    lv_task_handler();
    lv_tick_inc(millis() - lastTick);
    vTaskDelay(pdMS_TO_TICKS(10)); // Adjust the delay as necessary
}