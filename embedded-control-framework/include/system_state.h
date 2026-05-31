#ifndef SYSTEM_STATE_H
#define SYSTEM_STATE_H

typedef enum
{
    STATE_INIT = 0,
    STATE_IDLE,
    STATE_ARMED,
    STATE_ACTIVE,
    STATE_FAULT,
    STATE_RECOVERY

} system_state_t;

#endif
