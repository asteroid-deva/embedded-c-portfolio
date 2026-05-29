#ifndef SYSTEM_EVENTS_H
#define SYSTEM_EVENTS_H

typedef enum
{
    EVENT_NONE = 0,

    EVENT_BUTTON_PRESS,

    EVENT_SENSOR_TRIGGER,

    EVENT_UART_RECEIVED,

    EVENT_FAULT_DETECTED

} system_event_t;

#endif
