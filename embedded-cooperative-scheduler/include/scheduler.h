#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task.h"

#define MAX_TASKS 5

typedef struct
{
    task_t tasks[MAX_TASKS];

    int task_count;

} scheduler_t;

void scheduler_init(scheduler_t* scheduler);

int scheduler_add_task(scheduler_t* scheduler,
                       task_function_t task,
                       int period_ticks);

void scheduler_run(scheduler_t* scheduler);

#endif
