#ifndef FSM_H
#define FSM_H

#include "system_state.h"
#include "system_events.h"

system_state_t fsm_handle_event(
    system_state_t current_state,
    system_event_t event);

const char* state_to_str(
    system_state_t state);

#endif
