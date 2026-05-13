#include "software_timer.h"

void software_timer_init(software_timer_t *timer)
{
    if (!timer) {
        return;
    }

    timer->start_tick = 0;
    timer->timeout_ticks = 0;
    timer->active = false;
}

void software_timer_start(software_timer_t *timer,
                          uint32_t current_tick,
                          uint32_t timeout_ticks)
{
    if (!timer) {
        return;
    }

    timer->start_tick = current_tick;
    timer->timeout_ticks = timeout_ticks;
    timer->active = true;
}

void software_timer_stop(software_timer_t *timer)
{
    if (!timer) {
        return;
    }

    timer->active = false;
}

bool software_timer_expired(const software_timer_t *timer,
                            uint32_t current_tick)
{
    if (!timer || !timer->active) {
        return false;
    }

    return (current_tick - timer->start_tick) >= timer->timeout_ticks;
}
