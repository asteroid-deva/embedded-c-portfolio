#include "interrupt_simulator.h"

void fake_button_interrupt(event_queue_t* q)
{
    queue_push(q, EVENT_BUTTON_PRESS);
}

void fake_sensor_interrupt(event_queue_t* q)
{
    queue_push(q, EVENT_SENSOR_TRIGGER);
}

void fake_uart_interrupt(event_queue_t* q)
{
    queue_push(q, EVENT_UART_RECEIVED);
}
