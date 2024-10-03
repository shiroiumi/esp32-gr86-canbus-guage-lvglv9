#include "vars.h"
#include <string.h>

int32_t unit_value = 0;
char *unit = "rpm";
int32_t guage_min = 0;
int32_t guage_max = 9000;
int32_t guage_ticks = 91;
int32_t guage_major_tick_every = 10;
int32_t arc_min = 0;
int32_t arc_max = 9000;

int32_t get_var_unit_value()
{
    return unit_value;
}

void set_var_unit_value(int32_t value)
{
    unit_value = value;
}

const char *get_var_unit()
{
    return unit;
}
void set_var_unit(const char *value)
{
    strncpy(unit, value, sizeof(unit) - 1);
    unit[sizeof(unit) - 1] = '\0';
}

int32_t get_var_guage_min()
{
    return guage_min;
}

void set_var_guage_min(int32_t value)
{
    guage_min = value;
}

int32_t get_var_guage_max()
{
    return guage_max;
}

void set_var_guage_max(int32_t value)
{
    guage_max = value;
}

int32_t get_var_arc_min()
{
    return arc_min;
}

void set_var_arc_min(int32_t value)
{
    arc_min = value;
}

int32_t get_var_arc_max()
{
    return arc_max;
}

void set_var_arc_max(int32_t value)
{
    arc_max = value;
}

// Custom
int32_t get_var_guage_ticks()
{
    return guage_ticks;
}

void set_var_guage_ticks(int32_t value)
{
    guage_ticks = value;
}

int32_t get_var_guage_major_ticks_every()
{
    return guage_major_tick_every;
}

void set_var_guage_major_tick_every(int32_t value)
{
    guage_major_tick_every = value;
}
