#include "control/display_control.h"
#include "screen/vars.h"
#include "control/utilities.h"
#include <pthread.h>

GuageMode guage_mode = RPM;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

GuageMode get_guage_mode()
{
    pthread_mutex_lock(&mutex);
    GuageMode gm = guage_mode;
    pthread_mutex_unlock(&mutex);
    return gm;
}

void set_guage_mode_rpm()
{
    set_arc_guage_range(0, 9000);
    set_var_guage_major_tick_every(10);
    set_var_guage_ticks(91);
    set_var_unit("RPM");
}

void set_guage_mode_oil_temp()
{
    set_arc_guage_range(-20, 200);
    set_var_guage_major_tick_every(5);
    set_var_guage_ticks(61);
    set_var_unit("");
}

void set_guage_mode(GuageMode value)
{
    pthread_mutex_lock(&mutex);
    guage_mode = value;

    if (value == RPM)
    {
        set_guage_mode_rpm();
    }
    else if (value == OIL_TEMP)
    {
        set_guage_mode_oil_temp();
    }
    pthread_mutex_unlock(&mutex);
}