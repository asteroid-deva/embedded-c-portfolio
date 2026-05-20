#include "event_queue.h"

void queue_init(event_queue_t* q)
{
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}

bool queue_is_empty(const event_queue_t* q)
{
    return (q->count == 0);
}

bool queue_is_full(const event_queue_t* q)
{
    return (q->count == EVENT_QUEUE_SIZE);
}

bool queue_push(event_queue_t* q,
                system_event_t event)
{
    if (queue_is_full(q))
    {
        return false;
    }

    q->buffer[q->tail] = event;

    q->tail = (q->tail + 1) % EVENT_QUEUE_SIZE;

    q->count++;

    return true;
}

bool queue_pop(event_queue_t* q,
               system_event_t* event)
{
    if (queue_is_empty(q))
    {
        return false;
    }

    *event = q->buffer[q->head];

    q->head = (q->head + 1) % EVENT_QUEUE_SIZE;

    q->count--;

    return true;
}
