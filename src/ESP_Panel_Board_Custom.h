/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

// *INDENT-OFF*

/* Set to 1 if using a custom board */
#define ESP_PANEL_USE_CUSTOM_BOARD (1) // 0/1

#if ESP_PANEL_USE_CUSTOM_BOARD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// Please update the following macros to configure the LCD panel /////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Set to 1 when using an LCD panel */
#define ESP_PANEL_USE_LCD (1) // 0/1

#if ESP_PANEL_USE_LCD
/**
 * LCD Controller Name. Choose one of the following:
 *      - EK9716B
 *      - GC9A01, GC9B71, GC9503
 *      - ILI9341
 *      - NV3022B
 *      - SH8601
 *      - SPD2010
 *      - ST7262, ST7701, ST7789, ST7796, ST77916, ST77922
 */
#define ESP_PANEL_LCD_NAME ST77916

/* LCD resolution in pixels */
#define ESP_PANEL_LCD_WIDTH (360)
#define ESP_PANEL_LCD_HEIGHT (360)

/* LCD Bus Settings */
/**
 * If set to 1, the bus will skip to initialize the corresponding host. Users need to initialize the host in advance.
 * It is useful if other devices use the same host. Please ensure that the host is initialized only once.
 *
 * Set to 1 if only the RGB interface is used without the 3-wire SPI interface,
 */
#define ESP_PANEL_LCD_BUS_SKIP_INIT_HOST (0) // 0/1
/**
 * LCD Bus Type. Choose one of the following:
 *      - ESP_PANEL_BUS_TYPE_I2C (not ready)
 *      - ESP_PANEL_BUS_TYPE_SPI
 *      - ESP_PANEL_BUS_TYPE_QSPI
 *      - ESP_PANEL_BUS_TYPE_I80 (not ready)
 *      - ESP_PANEL_BUS_TYPE_RGB (only supported for ESP32-S3)
 */
#define ESP_PANEL_LCD_BUS_TYPE (ESP_PANEL_BUS_TYPE_SPI)
/**
 * LCD Bus Parameters.
 *
 * Please refer to https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/api-reference/peripherals/lcd.html and
 * https://docs.espressif.com/projects/esp-iot-solution/en/latest/display/lcd/index.html for more details.
 *
 */
#if ESP_PANEL_LCD_BUS_TYPE == ESP_PANEL_BUS_TYPE_SPI

#define ESP_PANEL_LCD_BUS_HOST_ID (1) // Typically set to 1
#define ESP_PANEL_LCD_SPI_IO_CS (5)
#if !ESP_PANEL_LCD_BUS_SKIP_INIT_HOST
#define ESP_PANEL_LCD_SPI_IO_SCK (7)
#define ESP_PANEL_LCD_SPI_IO_MOSI (6)
#define ESP_PANEL_LCD_SPI_IO_MISO (-1) // -1 if not used
#endif
#define ESP_PANEL_LCD_SPI_IO_DC (4)
#define ESP_PANEL_LCD_SPI_MODE (0) // 0/1/2/3, typically set to 0
#define ESP_PANEL_LCD_SPI_CLK_HZ (80 * 1000 * 1000)
// Should be an integer divisor of 80M, typically set to 40M
#define ESP_PANEL_LCD_SPI_TRANS_QUEUE_SZ (10) // Typically set to 10
#define ESP_PANEL_LCD_SPI_CMD_BITS (8)        // Typically set to 8
#define ESP_PANEL_LCD_SPI_PARAM_BITS (8)      // Typically set to 8

#elif ESP_PANEL_LCD_BUS_TYPE == ESP_PANEL_BUS_TYPE_QSPI

#define ESP_PANEL_LCD_BUS_HOST_ID (1) // Typically set to 1
#define ESP_PANEL_LCD_SPI_IO_CS (5)
#if !ESP_PANEL_LCD_BUS_SKIP_INIT_HOST
#define ESP_PANEL_LCD_SPI_IO_SCK (9)
#define ESP_PANEL_LCD_SPI_IO_DATA0 (10)
#define ESP_PANEL_LCD_SPI_IO_DATA1 (11)
#define ESP_PANEL_LCD_SPI_IO_DATA2 (12)
#define ESP_PANEL_LCD_SPI_IO_DATA3 (13)
#endif
#define ESP_PANEL_LCD_SPI_MODE (0) // 0/1/2/3, typically set to 0
#define ESP_PANEL_LCD_SPI_CLK_HZ (40 * 1000 * 1000)
// Should be an integer divisor of 80M, typically set to 40M
#define ESP_PANEL_LCD_SPI_TRANS_QUEUE_SZ (10) // Typically set to 10
#define ESP_PANEL_LCD_SPI_CMD_BITS (32)       // Typically set to 32
#define ESP_PANEL_LCD_SPI_PARAM_BITS (8)      // Typically set to 8

#elif ESP_PANEL_LCD_BUS_TYPE == ESP_PANEL_BUS_TYPE_RGB

#define ESP_PANEL_LCD_RGB_CLK_HZ (16 * 1000 * 1000)
#define ESP_PANEL_LCD_RGB_HPW (10)
#define ESP_PANEL_LCD_RGB_HBP (10)
#define ESP_PANEL_LCD_RGB_HFP (20)
#define ESP_PANEL_LCD_RGB_VPW (10)
#define ESP_PANEL_LCD_RGB_VBP (10)
#define ESP_PANEL_LCD_RGB_VFP (10)
#define ESP_PANEL_LCD_RGB_PCLK_ACTIVE_NEG (0) // 0: rising edge, 1: falling edge

// | 8-bit RGB888 | 16-bit RGB565 |
// |--------------|---------------|
#define ESP_PANEL_LCD_RGB_DATA_WIDTH (16)     // |      8       |      16       |
#define ESP_PANEL_LCD_RGB_PIXEL_BITS (16)     // |      24      |      16       |

#define ESP_PANEL_LCD_RGB_FRAME_BUF_NUM (1)   // 1/2/3
#define ESP_PANEL_LCD_RGB_BOUNCE_BUF_SIZE (0) // Bounce buffer size in bytes. This function is used to avoid screen drift.
                                              // To enable the bounce buffer, set it to a non-zero value. Typically set to `ESP_PANEL_LCD_WIDTH * 10`
                                              // The size of the Bounce Buffer must satisfy `width_of_lcd * height_of_lcd = size_of_buffer * N`,
                                              // where N is an even number.
#define ESP_PANEL_LCD_RGB_IO_HSYNC (46)
#define ESP_PANEL_LCD_RGB_IO_VSYNC (3)
#define ESP_PANEL_LCD_RGB_IO_DE (17) // -1 if not used
#define ESP_PANEL_LCD_RGB_IO_PCLK (9)
#define ESP_PANEL_LCD_RGB_IO_DISP (-1)  // -1 if not used

// | RGB565 | RGB666 | RGB888 |
// |--------|--------|--------|
#define ESP_PANEL_LCD_RGB_IO_DATA0 (10) // |   B0   |  B0-1  |   B0-3 |
#define ESP_PANEL_LCD_RGB_IO_DATA1 (11) // |   B1   |  B2    |   B4   |
#define ESP_PANEL_LCD_RGB_IO_DATA2 (12) // |   B2   |  B3    |   B5   |
#define ESP_PANEL_LCD_RGB_IO_DATA3 (13) // |   B3   |  B4    |   B6   |
#define ESP_PANEL_LCD_RGB_IO_DATA4 (14) // |   B4   |  B5    |   B7   |
#define ESP_PANEL_LCD_RGB_IO_DATA5 (21) // |   G0   |  G0    |   G0-2 |
#define ESP_PANEL_LCD_RGB_IO_DATA6 (47) // |   G1   |  G1    |   G3   |
#define ESP_PANEL_LCD_RGB_IO_DATA7 (48) // |   G2   |  G2    |   G4   |
#if ESP_PANEL_LCD_RGB_DATA_WIDTH > 8
#define ESP_PANEL_LCD_RGB_IO_DATA8 (45)  // |   G3   |  G3    |   G5   |
#define ESP_PANEL_LCD_RGB_IO_DATA9 (38)  // |   G4   |  G4    |   G6   |
#define ESP_PANEL_LCD_RGB_IO_DATA10 (39) // |   G5   |  G5    |   G7   |
#define ESP_PANEL_LCD_RGB_IO_DATA11 (40) // |   R0   |  R0-1  |   R0-3 |
#define ESP_PANEL_LCD_RGB_IO_DATA12 (41) // |   R1   |  R2    |   R4   |
#define ESP_PANEL_LCD_RGB_IO_DATA13 (42) // |   R2   |  R3    |   R5   |
#define ESP_PANEL_LCD_RGB_IO_DATA14 (2)  // |   R3   |  R4    |   R6   |
#define ESP_PANEL_LCD_RGB_IO_DATA15 (1)  // |   R4   |  R5    |   R7   |
#endif

#if !ESP_PANEL_LCD_BUS_SKIP_INIT_HOST
#define ESP_PANEL_LCD_3WIRE_SPI_IO_CS (0)
#define ESP_PANEL_LCD_3WIRE_SPI_IO_SCK (1)
#define ESP_PANEL_LCD_3WIRE_SPI_IO_SDA (2)
#define ESP_PANEL_LCD_3WIRE_SPI_CS_USE_EXPNADER (0)  // 0/1
#define ESP_PANEL_LCD_3WIRE_SPI_SCL_USE_EXPNADER (0) // 0/1
#define ESP_PANEL_LCD_3WIRE_SPI_SDA_USE_EXPNADER (0) // 0/1
#define ESP_PANEL_LCD_3WIRE_SPI_SCL_ACTIVE_EDGE (0)  // 0: rising edge, 1: falling edge
#define ESP_PANEL_LCD_FLAGS_AUTO_DEL_PANEL_IO (0)    // Delete the panel IO instance automatically if set to 1.
                                                     // If the 3-wire SPI pins are sharing other pins of the RGB interface to save GPIOs,
                                                     // Please set it to 1 to release the panel IO and its pins (except CS signal).
#define ESP_PANEL_LCD_FLAGS_MIRROR_BY_CMD (!ESP_PANEL_LCD_FLAGS_AUTO_DEL_PANEL_IO)
// The `mirror()` function will be implemented by LCD command if set to 1.
#endif

#else

#error "The function is not ready and will be implemented in the future."

#endif /* ESP_PANEL_LCD_BUS_TYPE */

/**
 * LCD Vendor Initialization Commands.
 *
 * Vendor specific initialization can be different between manufacturers, should consult the LCD supplier for
 * initialization sequence code. Please uncomment and change the following macro definitions. Otherwise, the LCD driver
 * will use the default initialization sequence code.
 *
 * There are two formats for the sequence code:
 *   1. Raw data: {command, (uint8_t []){ data0, data1, ... }, data_size, delay_ms}
 *   2. Formater: ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(delay_ms, command, { data0, data1, ... }) and
 *                ESP_PANEL_LCD_CMD_WITH_NONE_PARAM(delay_ms, command)
 */
#define ESP_PANEL_LCD_VENDOR_INIT_CMD()                                                                                                   \
    {                                                                                                                                     \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x08}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF2, {0x08}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x9B, {0x51}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x86, {0x53}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF2, {0x80}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x01}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF1, {0x01}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB0, {0x54}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB1, {0x3F}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB2, {0x2A}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB4, {0x46}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB5, {0x34}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB6, {0xD5}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB7, {0x30}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB8, {0x04}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBA, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBB, {0x08}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBC, {0x08}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBD, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC0, {0x80}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC1, {0x10}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC2, {0x37}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC3, {0x80}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC4, {0x10}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC5, {0x37}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC6, {0xA9}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC7, {0x41}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC8, {0x51}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC9, {0xA9}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xCA, {0x41}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xCB, {0x51}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD0, {0x91}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD1, {0x68}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD2, {0x69}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF5, {0x00, 0xA5}),                                                                         \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xDD, {0x35}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xDE, {0x35}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF1, {0x10}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x02}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE0, {0x70, 0x09, 0x12, 0x0C, 0x0B, 0x27, 0x38, 0x54, 0x4E, 0x19, 0x15, 0x15, 0x2C, 0x2F}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE1, {0x70, 0x08, 0x11, 0x0C, 0x0B, 0x27, 0x38, 0x43, 0x4C, 0x18, 0x14, 0x14, 0x2B, 0x2D}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x10}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF3, {0x10}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE0, {0x0A}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE1, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE2, {0x0B}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE3, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE4, {0xE0}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE5, {0x06}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE6, {0x21}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE7, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE8, {0x05}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xE9, {0x82}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xEA, {0xDF}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xEB, {0x89}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xEC, {0x20}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xED, {0x14}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xEE, {0xFF}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xEF, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF8, {0xFF}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF9, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xFA, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xFB, {0x30}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xFC, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xFD, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xFE, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xFF, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x60, {0x42}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x61, {0xE0}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x62, {0x40}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x63, {0x40}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x64, {0x02}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x65, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x66, {0x40}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x67, {0x03}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x68, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x69, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x6A, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x6B, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x70, {0x42}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x71, {0xE0}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x72, {0x40}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x73, {0x40}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x74, {0x02}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x75, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x76, {0x40}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x77, {0x03}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x78, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x79, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x7A, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x7B, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x80, {0x38}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x81, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x82, {0x04}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x83, {0x02}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x84, {0xDC}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x85, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x86, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x87, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x88, {0x38}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x89, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x8A, {0x06}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x8B, {0x02}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x8C, {0xDE}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x8D, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x8E, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x8F, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x90, {0x38}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x91, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x92, {0x08}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x93, {0x02}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x94, {0xE0}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x95, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x96, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x97, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x98, {0x38}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x99, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x9A, {0x0A}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x9B, {0x02}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x9C, {0xE2}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x9D, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x9E, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x9F, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA0, {0x38}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA1, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA2, {0x03}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA3, {0x02}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA4, {0xDB}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA5, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA6, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA7, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA8, {0x38}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA9, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xAA, {0x05}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xAB, {0x02}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xAC, {0xDD}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xAD, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xAE, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xAF, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB0, {0x38}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB1, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB2, {0x07}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB3, {0x02}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB4, {0xDF}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB5, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB6, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB7, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB8, {0x38}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB9, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBA, {0x09}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBB, {0x02}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBC, {0xE1}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBD, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBE, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xBF, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC0, {0x22}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC1, {0xAA}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC2, {0x65}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC3, {0x74}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC4, {0x47}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC5, {0x56}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC6, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC7, {0x88}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC8, {0x99}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC9, {0x33}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD0, {0x11}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD1, {0xAA}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD2, {0x65}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD3, {0x74}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD4, {0x47}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD5, {0x56}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD6, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD7, {0x88}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD8, {0x99}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD9, {0x33}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF3, {0x01}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x01}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF1, {0x01}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA0, {0x0B}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA3, {0x2A}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA5, {0xC3}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(1, 0xA3, {0x2B}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA5, {0xC3}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(1, 0xA3, {0x2C}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA5, {0xC3}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(1, 0xA3, {0x2D}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA5, {0xC3}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(1, 0xA3, {0x2E}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA5, {0xC3}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(1, 0xA3, {0x2F}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA5, {0xC3}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(1, 0xA3, {0x30}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA5, {0xC3}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(1, 0xA3, {0x31}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA5, {0xC3}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(1, 0xA3, {0x32}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA5, {0xC3}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(1, 0xA3, {0x33}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA5, {0xC3}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(1, 0xA0, {0x09}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF1, {0x10}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x2A, {0x00, 0x00, 0x01, 0x67}),                                                             \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x2B, {0x01, 0x68, 0x01, 0x68}),                                                             \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x4D, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x4E, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x4F, {0x00}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x4C, {0x01}),                                                                               \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(10, 0x4C, {0x00}),                                                                              \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x2A, {0x00, 0x00, 0x01, 0x67}),                                                             \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x2B, {0x00, 0x00, 0x01, 0x67}),                                                             \
        ESP_PANEL_LCD_CMD_WITH_NONE_PARAM(0, 0x21),                                                                                       \
        ESP_PANEL_LCD_CMD_WITH_NONE_PARAM(0, 0x11),                                                                                       \
        ESP_PANEL_LCD_CMD_WITH_NONE_PARAM(120, 0x29),                                                                                     \
    }

/* LCD Color Settings */
/* LCD color depth in bits */
#define ESP_PANEL_LCD_COLOR_BITS (18) // 8/16/18/24
/*
 * LCD RGB Element Order. Choose one of the following:
 *      - 0: RGB
 *      - 1: BGR
 */
#define ESP_PANEL_LCD_BGR_ORDER (0)    // 0/1
#define ESP_PANEL_LCD_INEVRT_COLOR (0) // 0/1

/* LCD Transformation Flags */
#define ESP_PANEL_LCD_SWAP_XY (0)  // 0/1
#define ESP_PANEL_LCD_MIRROR_X (0) // 0/1
#define ESP_PANEL_LCD_MIRROR_Y (0) // 0/1

/* LCD Other Settings */
/* Reset pin */
#define ESP_PANEL_LCD_IO_RST (15)   // IO num of RESET pin, set to -1 if not use
#define ESP_PANEL_LCD_RST_LEVEL (1) // Active level. 0: low level, 1: high level

#endif /* ESP_PANEL_USE_LCD */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// Please update the following macros to configure the touch panel ///////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Set to 1 when using an touch panel */
#define ESP_PANEL_USE_TOUCH (0) // 0/1
#if ESP_PANEL_USE_TOUCH
/**
 * Touch controller name. Choose one of the following:
 *      - CST816S
 *      - FT5x06
 *      - GT911, GT1151
 *      - ST1633, ST7123
 *      - TT21100
 *      - XPT2046
 */
#define ESP_PANEL_TOUCH_NAME TT21100

/* Touch resolution in pixels */
#define ESP_PANEL_TOUCH_H_RES (ESP_PANEL_LCD_WIDTH)  // Typically set to the same value as the width of LCD
#define ESP_PANEL_TOUCH_V_RES (ESP_PANEL_LCD_HEIGHT) // Typically set to the same value as the height of LCD

/* Touch Panel Bus Settings */
/**
 * If set to 1, the bus will skip to initialize the corresponding host. Users need to initialize the host in advance.
 * It is useful if other devices use the same host. Please ensure that the host is initialized only once.
 */
#define ESP_PANEL_TOUCH_BUS_SKIP_INIT_HOST (0) // 0/1
/**
 * Touch panel bus type. Choose one of the following:
 *      - ESP_PANEL_BUS_TYPE_I2C
 *      - ESP_PANEL_BUS_TYPE_SPI
 */
#define ESP_PANEL_TOUCH_BUS_TYPE (ESP_PANEL_BUS_TYPE_I2C)
/* Touch panel bus parameters */
#if ESP_PANEL_TOUCH_BUS_TYPE == ESP_PANEL_BUS_TYPE_I2C

#define ESP_PANEL_TOUCH_BUS_HOST_ID (0) // Typically set to 0
#define ESP_PANEL_TOUCH_I2C_ADDRESS (0) // Typically set to 0 to use the default address.
                                        // - For touchs with only one address, set to 0
                                        // - For touchs with multiple addresses, set to 0 or the address
                                        //   Like GT911, there are two addresses: 0x5D(default) and 0x14
#if !ESP_PANEL_TOUCH_BUS_SKIP_INIT_HOST
#define ESP_PANEL_TOUCH_I2C_CLK_HZ (400 * 1000)
// Typically set to 400K
#define ESP_PANEL_TOUCH_I2C_SCL_PULLUP (1) // 0/1
#define ESP_PANEL_TOUCH_I2C_SDA_PULLUP (1) // 0/1
#define ESP_PANEL_TOUCH_I2C_IO_SCL (18)
#define ESP_PANEL_TOUCH_I2C_IO_SDA (8)
#endif

#elif ESP_PANEL_TOUCH_BUS_TYPE == ESP_PANEL_BUS_TYPE_SPI

#define ESP_PANEL_TOUCH_BUS_HOST_ID (1) // Typically set to 1
#define ESP_PANEL_TOUCH_SPI_IO_CS (5)
#if !ESP_PANEL_TOUCH_BUS_SKIP_INIT_HOST
#define ESP_PANEL_TOUCH_SPI_IO_SCK (7)
#define ESP_PANEL_TOUCH_SPI_IO_MOSI (6)
#define ESP_PANEL_TOUCH_SPI_IO_MISO (9)
#endif
#define ESP_PANEL_TOUCH_SPI_CLK_HZ (1 * 1000 * 1000)
// Should be an integer divisor of 80M, typically set to 1M

#else

#error "The function is not ready and will be implemented in the future."

#endif /* ESP_PANEL_TOUCH_BUS_TYPE */

/* Touch Transformation Flags */
#define ESP_PANEL_TOUCH_SWAP_XY (0)  // 0/1
#define ESP_PANEL_TOUCH_MIRROR_X (0) // 0/1
#define ESP_PANEL_TOUCH_MIRROR_Y (0) // 0/1

/* Touch Other Settings */
/* Reset pin */
#define ESP_PANEL_TOUCH_IO_RST (-1)   // IO num of RESET pin, set to -1 if not use
                                      // For GT911, the RST pin is also used to configure the I2C address
#define ESP_PANEL_TOUCH_RST_LEVEL (0) // Active level. 0: low level, 1: high level
/* Interrupt pin */
#define ESP_PANEL_TOUCH_IO_INT (-1)   // IO num of INT pin, set to -1 if not use
                                      // For GT911, the INT pin is also used to configure the I2C address
#define ESP_PANEL_TOUCH_INT_LEVEL (0) // Active level. 0: low level, 1: high level

#endif /* ESP_PANEL_USE_TOUCH */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Please update the following macros to configure the backlight ////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ESP_PANEL_USE_BACKLIGHT (0) // 0/1
#if ESP_PANEL_USE_BACKLIGHT
/* Backlight pin */
#define ESP_PANEL_BACKLIGHT_IO (45)      // IO num of backlight pin
#define ESP_PANEL_BACKLIGHT_ON_LEVEL (1) // 0: low level, 1: high level

/* Set to 1 if you want to turn off the backlight after initializing the panel; otherwise, set it to turn on */
#define ESP_PANEL_BACKLIGHT_IDLE_OFF (0) // 0: on, 1: off

/* Set to 1 if use PWM for brightness control */
#define ESP_PANEL_LCD_BL_USE_PWM (1) // 0/1
#endif                               /* ESP_PANEL_USE_BACKLIGHT */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Please update the following macros to configure the IO expander //////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Set to 0 if not using IO Expander */
#define ESP_PANEL_USE_EXPANDER (0) // 0/1
#if ESP_PANEL_USE_EXPANDER
/**
 * IO expander name. Choose one of the following:
 *      - CH422G
 *      - HT8574
 *      - TCA95xx_8bit
 *      - TCA95xx_16bit
 */
#define ESP_PANEL_EXPANDER_NAME TCA95xx_8bit

/* IO expander Settings */
/**
 * If set to 1, the driver will skip to initialize the corresponding host. Users need to initialize the host in advance.
 * It is useful if other devices use the same host. Please ensure that the host is initialized only once.
 */
#define ESP_PANEL_EXPANDER_SKIP_INIT_HOST (0) // 0/1
/* IO expander parameters */
#define ESP_PANEL_EXPANDER_HOST_ID (0)        // Typically set to 0
#define ESP_PANEL_EXPANDER_I2C_ADDRESS (0x20) // The actual I2C address. Even for the same model of IC,
                                              // the I2C address may be different, and confirmation based on
                                              // the actual hardware connection is required
#if !ESP_PANEL_EXPANDER_SKIP_INIT_HOST
#define ESP_PANEL_EXPANDER_I2C_CLK_HZ (400 * 1000)
// Typically set to 400K
#define ESP_PANEL_EXPANDER_I2C_SCL_PULLUP (1) // 0/1
#define ESP_PANEL_EXPANDER_I2C_SDA_PULLUP (1) // 0/1
#define ESP_PANEL_EXPANDER_I2C_IO_SCL (18)
#define ESP_PANEL_EXPANDER_I2C_IO_SDA (8)
#endif
#endif /* ESP_PANEL_USE_EXPANDER */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Please utilize the following macros to execute any additional code if required. //////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// #define ESP_PANEL_BEGIN_START_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_EXPANDER_START_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_EXPANDER_END_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_LCD_START_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_LCD_END_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_TOUCH_START_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_TOUCH_END_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_BACKLIGHT_START_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_BACKLIGHT_END_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_END_FUNCTION( panel )

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// File Version ///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Do not change the following versions, they are used to check if the configurations in this file are compatible with
 * the current version of `ESP_Panel_Board_Custom.h` in the library. The detailed rules are as follows:
 *
 *   1. If the major version is not consistent, then the configurations in this file are incompatible with the library
 *      and must be replaced with the file from the library.
 *   2. If the minor version is not consistent, this file might be missing some new configurations, which will be set to
 *      default values. It is recommended to replace it with the file from the library.
 *   3. Even if the patch version is not consistent, it will not affect normal functionality.
 *
 */
#define ESP_PANEL_BOARD_CUSTOM_FILE_VERSION_MAJOR 0
#define ESP_PANEL_BOARD_CUSTOM_FILE_VERSION_MINOR 2
#define ESP_PANEL_BOARD_CUSTOM_FILE_VERSION_PATCH 2

#endif /* ESP_PANEL_USE_CUSTOM_BOARD */

// *INDENT-OFF*
