#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <stdint.h>
#include <stdbool.h>

/* System states */
typedef enum {
    STATE_IDLE = 0,
    STATE_ARMED,
    STATE_ACTIVE,
    STATE_FAILSAFE,
    STATE_MAX
} system_state_t;

/* Events that trigger transitions */
typedef enum {
    EVENT_NONE = 0,
    EVENT_ARM,
    EVENT_DISARM,
    EVENT_START,
    EVENT_STOP,
    EVENT_SIGNAL_LOST,
    EVENT_SIGNAL_RESTORED,
    EVENT_ERROR,
    EVENT_MAX
} system_event_t;

/* State machine context */
typedef struct {
    system_state_t current_state;
} state_machine_t;

/* Initialize state machine */
void state_machine_init(state_machine_t *sm);

/* Handle event and update state */
bool state_machine_handle_event(state_machine_t *sm, system_event_t event);

/* Get current state */
system_state_t state_machine_get_state(const state_machine_t *sm);

#endif /* STATE_MACHINE_H */
