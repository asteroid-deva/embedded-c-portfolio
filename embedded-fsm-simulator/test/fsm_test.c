#include <stdio.h>

#include "fsm.h"
#include "event_queue.h"

int main(void)
{
    system_state_t state = STATE_INIT;

    event_queue_t queue;

    queue_init(&queue);

    queue_push(&queue, EVT_INIT_DONE);
    queue_push(&queue, EVT_CHECKS_OK);
    queue_push(&queue, EVT_START);
    queue_push(&queue, EVT_FAULT);
    queue_push(&queue, EVT_RECOVER);
    queue_push(&queue, EVT_RECOVERY_DONE);

    system_event_t event;

    printf("Starting Queue-Driven FSM Test\n\n");

    while (!queue_is_empty(&queue))
    {
        queue_pop(&queue, &event);

        printf("Event: %d | State: %s -> ",
               event,
               state_to_str(state));

        state = fsm_handle_event(state, event);

        printf("%s\n",
               state_to_str(state));
    }

    return 0;
}
