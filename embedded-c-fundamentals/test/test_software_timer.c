#include <stdio.h>
#include <assert.h>
#include "software_timer.h"

int main(void)
{
    software_timer_t timer;
    uint32_t tick = 0;

    software_timer_init(&timer);

    /* Timer should not be active initially */
    assert(software_timer_expired(&timer, tick) == false);

    /* Start timer with timeout = 10 ticks */
    software_timer_start(&timer, tick, 10);

    /* Advance time, but not enough */
    tick = 5;
    assert(software_timer_expired(&timer, tick) == false);

    /* Reach timeout */
    tick = 10;
    assert(software_timer_expired(&timer, tick) == true);

    /* Stop timer */
    software_timer_stop(&timer);
    tick = 20;
    assert(software_timer_expired(&timer, tick) == false);

    printf("Software timer tests passed.\n");
    return 0;
}
