#include <stdio.h>

#include "scheduler.h"

void sensor_task(void)
{
    printf("Sensor task executed\n");
}

void control_task(void)
{
    printf("Control task executed\n");
}

void health_task(void)
{
    printf("Health monitor task executed\n");
}

int main(void)
{
    scheduler_t scheduler;

    scheduler_init(&scheduler);

    scheduler_add_task(&scheduler,
                       sensor_task,
                       2);

    scheduler_add_task(&scheduler,
                       control_task,
                       4);

    scheduler_add_task(&scheduler,
                       health_task,
                       6);

    printf("Starting Cooperative Scheduler\n\n");

    for (int tick = 0; tick < 20; tick++)
    {
        printf("Tick: %d\n", tick);

        scheduler_run(&scheduler);
    }

    return 0;
}
