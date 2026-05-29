#include <stdio.h>

#include "event_handler.h"

void handle_event(system_event_t event)
{
    switch(event)
    {
        case EVENT_BUTTON_PRESS:
            printf("Handling Button Press\n");
            break;

        case EVENT_SENSOR_TRIGGER:
            printf("Handling Sensor Trigger\n");
            break;

        case EVENT_UART_RECEIVED:
            printf("Handling UART Event\n");
            break;

        case EVENT_FAULT_DETECTED:
            printf("Handling Fault Event\n");
            break;

        default:
            break;
    }
}
