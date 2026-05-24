#ifndef SOFTWARE_TIMER_H
#define SOFTWARE_TIMER_H

#include <stdbool.h>

typedef struct
{
    int counter;
    int period;
} software_timer_t;

void timer_init(software_timer_t* timer,
                int period);

bool timer_tick(software_timer_t* timer);

#endif
