#include <stdio.h>

#include "scheduler.h"

void scheduler_init(scheduler_t* scheduler)
{
    scheduler->task_count = 0;
}

int scheduler_add_task(scheduler_t* scheduler,
                       task_function_t task,
                       int period_ticks)
{
    if (scheduler->task_count >= MAX_TASKS)
    {
        return -1;
    }

    task_t* new_task =
        &scheduler->tasks[scheduler->task_count];

    new_task->task = task;

    new_task->period_ticks = period_ticks;

    new_task->elapsed_ticks = 0;

    scheduler->task_count++;

    return 0;
}

void scheduler_run(scheduler_t* scheduler)
{
    for (int i = 0; i < scheduler->task_count; i++)
    {
        task_t* task = &scheduler->tasks[i];

        task->elapsed_ticks++;

        if (task->elapsed_ticks >= task->period_ticks)
        {
            task->task();

            task->elapsed_ticks = 0;
        }
    }
}
