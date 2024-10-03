/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --user-data-dir=C:\Users\safer\AppData\Roaming\eezstudio --app-path=C:\Users\safer\AppData\Local\Programs\eezstudio\resources\app.asar --no-sandbox --no-zygote --node-integration-in-worker --video-capture-use-gpu-memory-buffer --lang=en-US --device-scale-factor=1 --num-raster-threads=4 --enable-main-frame-before-activation --renderer-client-id=5 --time-ticks-at-unix-epoch=-1727581347559362 --launch-time-ticks=353808314259 --field-trial-handle=2928,i,3208797933737345546,5858337929302383941,262144 --disable-features=SpareRendererForSitePerProcess,WinDelaySpellcheckServiceInit,WinRetrieveSuggestionsOnlyOnDemand --variations-seed-version --mojo-platform-channel-handle=2924 /prefetch:1
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef UI_FONT_EXCLUDED_16
#define UI_FONT_EXCLUDED_16 1
#endif

#if UI_FONT_EXCLUDED_16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+002B "+" */
    0x37, 0xfe, 0x63, 0x0,

    /* U+002D "-" */
    0xff, 0xc0,

    /* U+002F "/" */
    0x7, 0xe, 0x1c, 0x1c, 0x38, 0x38, 0x70, 0x70,
    0xe0,

    /* U+0030 "0" */
    0x7f, 0x7f, 0xf8, 0xfc, 0x7e, 0x3f, 0x1f, 0x8f,
    0xff, 0x7f, 0x0,

    /* U+0031 "1" */
    0xff, 0xf1, 0xc7, 0x1c, 0x71, 0xc7, 0x1c,

    /* U+0032 "2" */
    0xff, 0xff, 0xc0, 0xef, 0xff, 0xff, 0x3, 0x81,
    0xff, 0xff, 0x80,

    /* U+0033 "3" */
    0xff, 0x7f, 0xc0, 0xff, 0xff, 0xf8, 0x1c, 0xf,
    0xff, 0xff, 0x0,

    /* U+0034 "4" */
    0xe3, 0xf1, 0xf8, 0xff, 0xff, 0xf8, 0x1c, 0xe,
    0x7, 0x3, 0x80,

    /* U+0035 "5" */
    0xff, 0xff, 0xf8, 0x1f, 0xef, 0xf8, 0x1c, 0xf,
    0xff, 0xff, 0x80,

    /* U+0036 "6" */
    0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0x1f, 0x8f,
    0xff, 0x7f, 0x80,

    /* U+0037 "7" */
    0xff, 0x7f, 0xc0, 0xe0, 0x70, 0x38, 0x1c, 0xe,
    0x7, 0x3, 0x80,

    /* U+0038 "8" */
    0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0x1f, 0x8f,
    0xff, 0x7f, 0x0,

    /* U+0039 "9" */
    0xff, 0x7f, 0xf8, 0xff, 0xff, 0xf8, 0x1c, 0xf,
    0xff, 0xff, 0x80,

    /* U+0041 "A" */
    0x7f, 0xdf, 0xff, 0x83, 0xf0, 0x7f, 0xff, 0xff,
    0xf8, 0x3f, 0x7, 0xe0, 0xe0,

    /* U+0042 "B" */
    0xff, 0xdf, 0xfb, 0x83, 0xff, 0xef, 0xfd, 0xc1,
    0xf8, 0x3f, 0xfe, 0xff, 0xc0,

    /* U+0043 "C" */
    0x7f, 0xff, 0xff, 0x80, 0x70, 0xe, 0x1, 0xc0,
    0x38, 0x7, 0xff, 0x7f, 0xe0,

    /* U+0044 "D" */
    0xff, 0xdf, 0xff, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0xff, 0xff, 0xc0,

    /* U+0045 "E" */
    0x7f, 0xff, 0xff, 0x80, 0x7f, 0xef, 0xfd, 0xc0,
    0x38, 0x7, 0xff, 0x7f, 0xe0,

    /* U+0046 "F" */
    0x7f, 0xff, 0xff, 0x80, 0x70, 0xf, 0xfd, 0xff,
    0xb8, 0x7, 0x0, 0xe0, 0x0,

    /* U+0047 "G" */
    0x7f, 0xff, 0xff, 0x80, 0x77, 0xfe, 0xff, 0xc1,
    0xf8, 0x3f, 0xff, 0x7f, 0xe0,

    /* U+0048 "H" */
    0xe0, 0xfc, 0x1f, 0x83, 0xff, 0xff, 0xff, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xe0,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xe0,

    /* U+004A "J" */
    0x0, 0xe0, 0x1c, 0x3, 0x80, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0xff, 0xff, 0xc0,

    /* U+004B "K" */
    0xe3, 0xdc, 0x73, 0x9e, 0x7f, 0x8f, 0xe1, 0xce,
    0x39, 0xe7, 0x1e, 0xe1, 0xc0,

    /* U+004C "L" */
    0xe0, 0x1c, 0x3, 0x80, 0x70, 0xe, 0x1, 0xc0,
    0x38, 0x7, 0xff, 0x7f, 0xe0,

    /* U+004D "M" */
    0x60, 0x6f, 0xf, 0xf9, 0xff, 0x9f, 0xff, 0xfe,
    0xf7, 0xef, 0x7e, 0x67, 0xe4, 0x70,

    /* U+004E "N" */
    0x70, 0xff, 0x1f, 0xe3, 0xfe, 0x7e, 0xef, 0xcf,
    0xf8, 0xff, 0x1f, 0xe1, 0xc0,

    /* U+004F "O" */
    0x7f, 0xdf, 0xff, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0xff, 0x7f, 0xc0,

    /* U+0050 "P" */
    0xff, 0xdf, 0xff, 0x83, 0xf0, 0x7f, 0xff, 0xff,
    0xb8, 0x7, 0x0, 0xe0, 0x0,

    /* U+0051 "Q" */
    0x7f, 0xcf, 0xfe, 0xe0, 0xee, 0xe, 0xe3, 0xee,
    0x3e, 0xe3, 0xef, 0xfe, 0x7f, 0xf0, 0x6,

    /* U+0052 "R" */
    0xff, 0xdf, 0xff, 0x83, 0xf0, 0x7f, 0xff, 0xff,
    0xb8, 0xe7, 0xe, 0xe1, 0xe0,

    /* U+0053 "S" */
    0xff, 0xff, 0xff, 0x80, 0x7f, 0xff, 0xfe, 0x1,
    0xc0, 0x3f, 0xfe, 0xff, 0xc0,

    /* U+0054 "T" */
    0xff, 0xff, 0xfc, 0x38, 0x7, 0x0, 0xe0, 0x1c,
    0x3, 0x80, 0x70, 0xe, 0x0,

    /* U+0055 "U" */
    0xe0, 0xfc, 0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0xff, 0x7f, 0xc0,

    /* U+0056 "V" */
    0xf1, 0xce, 0x39, 0xcf, 0x1d, 0xc3, 0xf8, 0x3e,
    0x7, 0xc0, 0x70, 0xe, 0x0,

    /* U+0057 "W" */
    0xe3, 0x8f, 0xc7, 0x1d, 0xdf, 0x7b, 0xbe, 0xe7,
    0x6d, 0xcf, 0xdf, 0x8f, 0x1e, 0x1e, 0x3c, 0x1c,
    0x70,

    /* U+0058 "X" */
    0x71, 0xcf, 0x78, 0xfe, 0xf, 0x80, 0xe0, 0x3e,
    0xf, 0xe3, 0xde, 0x71, 0xc0,

    /* U+0059 "Y" */
    0xe0, 0xfc, 0x1f, 0x83, 0xff, 0xff, 0xfe, 0x1,
    0xc0, 0x3f, 0xff, 0xff, 0xc0,

    /* U+005A "Z" */
    0xff, 0xdf, 0xfc, 0x1f, 0x87, 0xe1, 0xf0, 0xfc,
    0x3f, 0x7, 0xff, 0xff, 0xe0,

    /* U+0061 "a" */
    0x7f, 0xdf, 0xff, 0x83, 0xf0, 0x7f, 0xff, 0xff,
    0xf8, 0x3f, 0x7, 0xe0, 0xe0,

    /* U+0062 "b" */
    0xff, 0xdf, 0xfb, 0x83, 0xff, 0xef, 0xfd, 0xc1,
    0xf8, 0x3f, 0xfe, 0xff, 0xc0,

    /* U+0063 "c" */
    0x7f, 0xff, 0xff, 0x80, 0x70, 0xe, 0x1, 0xc0,
    0x38, 0x7, 0xff, 0x7f, 0xe0,

    /* U+0064 "d" */
    0xff, 0xdf, 0xff, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0xff, 0xff, 0xc0,

    /* U+0065 "e" */
    0x7f, 0xff, 0xff, 0x80, 0x7f, 0xef, 0xfd, 0xc0,
    0x38, 0x7, 0xff, 0x7f, 0xe0,

    /* U+0066 "f" */
    0x7f, 0xff, 0xff, 0x80, 0x70, 0xf, 0xfd, 0xff,
    0xb8, 0x7, 0x0, 0xe0, 0x0,

    /* U+0067 "g" */
    0x7f, 0xff, 0xff, 0x80, 0x77, 0xfe, 0xff, 0xc1,
    0xf8, 0x3f, 0xff, 0x7f, 0xe0,

    /* U+0068 "h" */
    0xe0, 0xfc, 0x1f, 0x83, 0xff, 0xff, 0xff, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xe0,

    /* U+0069 "i" */
    0xff, 0xff, 0xff, 0xe0,

    /* U+006A "j" */
    0x0, 0xe0, 0x1c, 0x3, 0x80, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0xff, 0xff, 0xc0,

    /* U+006B "k" */
    0xe3, 0xdc, 0x73, 0x9e, 0x7f, 0x8f, 0xe1, 0xce,
    0x39, 0xe7, 0x1e, 0xe1, 0xc0,

    /* U+006C "l" */
    0xe0, 0x1c, 0x3, 0x80, 0x70, 0xe, 0x1, 0xc0,
    0x38, 0x7, 0xff, 0x7f, 0xe0,

    /* U+006D "m" */
    0x60, 0x6f, 0xf, 0xf9, 0xff, 0x9f, 0xff, 0xfe,
    0xf7, 0xef, 0x7e, 0x67, 0xe4, 0x70,

    /* U+006E "n" */
    0x70, 0xff, 0x1f, 0xe3, 0xfe, 0x7e, 0xef, 0xcf,
    0xf8, 0xff, 0x1f, 0xe1, 0xc0,

    /* U+006F "o" */
    0x7f, 0xdf, 0xff, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0xff, 0x7f, 0xc0,

    /* U+0070 "p" */
    0xff, 0xdf, 0xff, 0x83, 0xf0, 0x7f, 0xff, 0xff,
    0xb8, 0x7, 0x0, 0xe0, 0x0,

    /* U+0071 "q" */
    0x7f, 0xcf, 0xfe, 0xe0, 0xee, 0xe, 0xe3, 0xee,
    0x3e, 0xe3, 0xef, 0xfe, 0x7f, 0xf0, 0x6,

    /* U+0072 "r" */
    0xff, 0xdf, 0xff, 0x83, 0xf0, 0x7f, 0xff, 0xff,
    0xb8, 0xe7, 0xe, 0xe1, 0xe0,

    /* U+0073 "s" */
    0xff, 0xff, 0xff, 0x80, 0x7f, 0xff, 0xfe, 0x1,
    0xc0, 0x3f, 0xfe, 0xff, 0xc0,

    /* U+0074 "t" */
    0xff, 0xff, 0xfc, 0x38, 0x7, 0x0, 0xe0, 0x1c,
    0x3, 0x80, 0x70, 0xe, 0x0,

    /* U+0075 "u" */
    0xe0, 0xfc, 0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0xff, 0x7f, 0xc0,

    /* U+0076 "v" */
    0xf1, 0xce, 0x39, 0xcf, 0x1d, 0xc3, 0xf8, 0x3e,
    0x7, 0xc0, 0x70, 0xe, 0x0,

    /* U+0077 "w" */
    0xe3, 0x8f, 0xc7, 0x1d, 0xdf, 0x7b, 0xbe, 0xe7,
    0x6d, 0xcf, 0xdf, 0x8f, 0x1e, 0x1e, 0x3c, 0x1c,
    0x70,

    /* U+0078 "x" */
    0x71, 0xcf, 0x78, 0xfe, 0xf, 0x80, 0xe0, 0x3e,
    0xf, 0xe3, 0xde, 0x71, 0xc0,

    /* U+0079 "y" */
    0xe0, 0xfc, 0x1f, 0x83, 0xff, 0xff, 0xfe, 0x1,
    0xc0, 0x3f, 0xff, 0xff, 0xc0,

    /* U+007A "z" */
    0xff, 0xdf, 0xfc, 0x1f, 0x87, 0xe1, 0xf0, 0xfc,
    0x3f, 0x7, 0xff, 0xff, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 51, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 92, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 5, .adv_w = 92, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 7, .adv_w = 154, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 161, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 27, .adv_w = 110, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 34, .adv_w = 174, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 45, .adv_w = 174, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 56, .adv_w = 174, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 67, .adv_w = 174, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 174, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 89, .adv_w = 174, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 100, .adv_w = 174, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 111, .adv_w = 174, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 122, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 135, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 148, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 187, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 200, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 72, .box_w = 3, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 230, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 256, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 269, .adv_w = 223, .box_w = 12, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 283, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 296, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 322, .adv_w = 205, .box_w = 12, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 337, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 363, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 376, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 389, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 402, .adv_w = 274, .box_w = 15, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 419, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 432, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 445, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 458, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 471, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 484, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 510, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 523, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 536, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 549, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 562, .adv_w = 72, .box_w = 3, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 566, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 579, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 592, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 605, .adv_w = 223, .box_w = 12, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 619, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 632, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 645, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 658, .adv_w = 205, .box_w = 12, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 673, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 686, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 699, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 712, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 725, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 738, .adv_w = 274, .box_w = 15, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 755, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 768, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 781, .adv_w = 205, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0xb, 0xd
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 14, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 3, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    },
    {
        .range_start = 47, .range_length = 11, .glyph_id_start = 4,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 65, .range_length = 26, .glyph_id_start = 15,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 41,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 4,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_excluded_16 = {
#else
lv_font_t ui_font_excluded_16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 10,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .fallback = NULL,
    .user_data = NULL
};



#endif /*#if UI_FONT_EXCLUDED_16*/

