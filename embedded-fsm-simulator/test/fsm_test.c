#include <stdio.h>

#include "fsm.h"
#include "event_queue.h"
#include "software_timer.h"

int main(void)
{
    system_state_t state = STATE_INIT;

    event_queue_t queue;

    software_timer_t timer;

    queue_init(&queue);

    timer_init(&timer, 3);

    queue_push(&queue, EVT_INIT_DONE);

    int ticks = 0;

    printf("Starting Timer-Driven FSM Test\n\n");

    while (ticks < 15)
    {
        if (timer_tick(&timer))
        {
            queue_push(&queue, EVT_CHECKS_OK);
        }

        system_event_t event;

        while (!queue_is_empty(&queue))
        {
            queue_pop(&queue, &event);

            printf("Event: %d | %s -> ",
                   event,
                   state_to_str(state));

            state = fsm_handle_event(state, event);

            printf("%s\n",
                   state_to_str(state));

            if (state == STATE_READY)
            {
                queue_push(&queue, EVT_START);
            }

            if (state == STATE_RUNNING && ticks > 8)
            {
                queue_push(&queue, EVT_FAULT);
            }

            if (state == STATE_FAULT)
            {
                queue_push(&queue, EVT_RECOVER);
            }

            if (state == STATE_RECOVERY)
            {
                queue_push(&queue, EVT_RECOVERY_DONE);
            }
        }

        ticks++;
    }

    return 0;
}
