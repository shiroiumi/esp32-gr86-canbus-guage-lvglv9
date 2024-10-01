#include "vars.h"

int32_t engine_temperature = 0;

int32_t get_var_engine_temperature()
{
    return engine_temperature;
}
void set_var_engine_temperature(int32_t value)
{
    engine_temperature = value;
}