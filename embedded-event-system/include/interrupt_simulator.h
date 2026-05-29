#ifndef INTERRUPT_SIMULATOR_H
#define INTERRUPT_SIMULATOR_H

#include "event_queue.h"

void fake_button_interrupt(event_queue_t* q);

void fake_sensor_interrupt(event_queue_t* q);

void fake_uart_interrupt(event_queue_t* q);

#endif
