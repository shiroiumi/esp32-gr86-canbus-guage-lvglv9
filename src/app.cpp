#include <Arduino.h>
#include "lvgl_port_v9.h"
#include <ESP_Panel_Library.h>
#include "screen/ui.h"
#include "screen/vars.h"
#include <CAN.h>

ulong lastTick = 0;

void on_can_packet_receive(int packetSize)
{
    long id = CAN.packetId();
    int data[8];
    int i = 0;
    while (CAN.available())
    {
        data[i++] = CAN.read();
    }
    set_var_engine_temperature(data[3] - 40);
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
    CAN.setPins(17, 16);
    do
    {
        Serial.println("Waiting on CANBUS");
        vTaskDelay(pdMS_TO_TICKS(2500));
    } while (!CAN.begin(500E3));
    CAN.filter(0x345);
    CAN.onReceive(on_can_packet_receive);
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