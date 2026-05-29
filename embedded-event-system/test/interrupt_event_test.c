#include <stdio.h>

#include "event_queue.h"
#include "interrupt_simulator.h"
#include "event_handler.h"

int main(void)
{
    event_queue_t queue;

    queue_init(&queue);

    printf("Starting Interrupt Event Test\n\n");

    fake_button_interrupt(&queue);

    fake_sensor_interrupt(&queue);

    fake_uart_interrupt(&queue);

    system_event_t event;

    while(!queue_is_empty(&queue))
    {
        queue_pop(&queue, &event);

        printf("Main Loop Received Event: %d\n",
               event);

        handle_event(event);
    }

    return 0;
}
