#include <stdio.h>
#include "event_queue.h"

int main(void)
{
    event_queue_t queue;

    queue_init(&queue);

    queue_push(&queue, EVT_INIT_DONE);
    queue_push(&queue, EVT_CHECKS_OK);
    queue_push(&queue, EVT_START);

    system_event_t event;

    printf("Queue Test\n\n");

    while (!queue_is_empty(&queue))
    {
        queue_pop(&queue, &event);

        printf("Popped Event: %d\n", event);
    }

    return 0;
}
