#ifndef SYSTEM_EVENTS_H
#define SYSTEM_EVENTS_H

typedef enum
{
    EVT_NONE = 0,

    EVT_BOOT_COMPLETE,
    EVT_ARM,
    EVT_START,
    EVT_STOP,

    EVT_FAULT,

    EVT_RECOVER,
    EVT_RECOVERY_DONE

} system_event_t;

#endif
