#include "fsm.h"

const char* state_to_str(
    system_state_t state)
{
    switch(state)
    {
        case STATE_INIT: return "INIT";
        case STATE_IDLE: return "IDLE";
        case STATE_ARMED: return "ARMED";
        case STATE_ACTIVE: return "ACTIVE";
        case STATE_FAULT: return "FAULT";
        case STATE_RECOVERY: return "RECOVERY";

        default: return "UNKNOWN";
    }
}

system_state_t fsm_handle_event(
    system_state_t current_state,
    system_event_t event)
{
    switch(current_state)
    {
        case STATE_INIT:

            if(event == EVT_BOOT_COMPLETE)
                return STATE_IDLE;

            break;

        case STATE_IDLE:

            if(event == EVT_ARM)
                return STATE_ARMED;

            break;

        case STATE_ARMED:

            if(event == EVT_START)
                return STATE_ACTIVE;

            if(event == EVT_FAULT)
                return STATE_FAULT;

            break;

        case STATE_ACTIVE:

            if(event == EVT_STOP)
                return STATE_IDLE;

            if(event == EVT_FAULT)
                return STATE_FAULT;

            break;

        case STATE_FAULT:

            if(event == EVT_RECOVER)
                return STATE_RECOVERY;

            break;

        case STATE_RECOVERY:

            if(event == EVT_RECOVERY_DONE)
                return STATE_IDLE;

            break;
    }

    return current_state;
}
