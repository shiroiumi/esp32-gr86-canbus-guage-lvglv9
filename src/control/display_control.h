#ifndef CONTROL_DISPLAY_CONTROL_H
#define CONTROL_DISPLAY_CONTROL_H

#ifdef __cplusplus
extern "C"
{
#endif
    typedef enum
    {
        RPM,
        OIL_TEMP
    } GuageMode;

    extern GuageMode get_guage_mode();
    extern void set_guage_mode(GuageMode mode);
#ifdef __cplusplus
}
#endif
#endif