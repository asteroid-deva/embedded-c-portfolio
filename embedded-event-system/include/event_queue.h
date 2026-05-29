#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include <stdbool.h>
#include "system_events.h"

#define EVENT_QUEUE_SIZE 8

typedef struct
{
    system_event_t buffer[EVENT_QUEUE_SIZE];

    volatile int head;

    volatile int tail;

    volatile int count;

} event_queue_t;

void queue_init(event_queue_t* q);

bool queue_push(event_queue_t* q,
                system_event_t event);

bool queue_pop(event_queue_t* q,
               system_event_t* event);

bool queue_is_empty(const event_queue_t* q);

bool queue_is_full(const event_queue_t* q);

#endif
