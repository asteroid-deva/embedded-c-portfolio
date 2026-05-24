#include "software_timer.h"

void timer_init(software_timer_t* timer,
                int period)
{
    timer->counter = 0;
    timer->period = period;
}

bool timer_tick(software_timer_t* timer)
{
    timer->counter++;

    if (timer->counter >= timer->period)
    {
        timer->counter = 0;
        return true;
    }

    return false;
}
