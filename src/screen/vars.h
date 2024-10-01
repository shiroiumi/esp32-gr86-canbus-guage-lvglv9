#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

    // enum declarations

    // Flow global variables

    enum FlowGlobalVariables
    {
        FLOW_GLOBAL_VARIABLE_ENGINE_TEMPERATURE = 0
    };

    // Native global variables
    int32_t get_var_engine_temperature();
    void set_var_engine_temperature(int32_t value);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/