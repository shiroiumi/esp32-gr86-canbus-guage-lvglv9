#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

    // Flow global variables

    enum FlowGlobalVariables
    {
        FLOW_GLOBAL_VARIABLE_UNIT_VALUE = 0,
        FLOW_GLOBAL_VARIABLE_UNIT = 1,
        FLOW_GLOBAL_VARIABLE_GUAGE_MIN = 2,
        FLOW_GLOBAL_VARIABLE_GUAGE_MAX = 3,
        FLOW_GLOBAL_VARIABLE_ARC_MAX = 4,
        FLOW_GLOBAL_VARIABLE_ARC_MIN = 5
    };

    // Native global variables

    int32_t get_var_unit_value();
    void set_var_unit_value(int32_t value);

    const char *get_var_unit();
    void set_var_unit(const char *value);

    int32_t get_var_guage_min();
    void set_var_guage_min(int32_t value);
    int32_t get_var_guage_max();
    void set_var_guage_max(int32_t value);
    int32_t get_var_arc_max();
    void set_var_arc_max(int32_t value);
    int32_t get_var_arc_min();
    void set_var_arc_min(int32_t value);
    void set_var_arc_max(int32_t value);

    // Custom
    int32_t get_var_guage_ticks();
    void set_var_guage_ticks(int32_t value);
    int32_t get_var_guage_major_ticks_every();
    void set_var_guage_major_tick_every(int32_t value);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/