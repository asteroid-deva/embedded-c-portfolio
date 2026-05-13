#include "state_machine.h"

void state_machine_init(state_machine_t *sm)
{
    if (!sm) {
        return;
    }

    sm->current_state = STATE_IDLE;
}

system_state_t state_machine_get_state(const state_machine_t *sm)
{
    return sm->current_state;
}

bool state_machine_handle_event(state_machine_t *sm, system_event_t event)
{
    if (!sm) {
        return false;
    }

    switch (sm->current_state) {

    case STATE_IDLE:
        if (event == EVENT_ARM) {
            sm->current_state = STATE_ARMED;
            return true;
        }
        break;

    case STATE_ARMED:
        if (event == EVENT_START) {
            sm->current_state = STATE_ACTIVE;
            return true;
        }
        if (event == EVENT_DISARM) {
            sm->current_state = STATE_IDLE;
            return true;
        }
        break;

    case STATE_ACTIVE:
        if (event == EVENT_STOP) {
            sm->current_state = STATE_ARMED;
            return true;
        }
        if (event == EVENT_SIGNAL_LOST || event == EVENT_ERROR) {
            sm->current_state = STATE_FAILSAFE;
            return true;
        }
        break;

    case STATE_FAILSAFE:
        if (event == EVENT_SIGNAL_RESTORED || event == EVENT_DISARM) {
            sm->current_state = STATE_IDLE;
            return true;
        }
        break;

    default:
        break;
    }

    return false;
}
