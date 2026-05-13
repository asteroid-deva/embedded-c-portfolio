#ifndef SOFTWARE_TIMER_H
#define SOFTWARE_TIMER_H

#include <stdint.h>
#include <stdbool.h>

/* Software timer structure */
typedef struct {
    uint32_t start_tick;
    uint32_t timeout_ticks;
    bool active;
} software_timer_t;

/* Initialize timer */
void software_timer_init(software_timer_t *timer);

/* Start timer with timeout */
void software_timer_start(software_timer_t *timer, uint32_t current_tick, uint32_t timeout_ticks);

/* Stop timer */
void software_timer_stop(software_timer_t *timer);

/* Check if timer has expired */
bool software_timer_expired(const software_timer_t *timer, uint32_t current_tick);

#endif /* SOFTWARE_TIMER_H */
