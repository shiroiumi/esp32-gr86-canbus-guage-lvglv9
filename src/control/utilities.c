#include "control/utilities.h"
#include "screen/vars.h"

void set_arc_guage_range(int32_t min, int32_t max)
{
    set_var_arc_min(min);
    set_var_arc_max(max);
    set_var_guage_min(min);
    set_var_guage_max(max);
}
