#ifndef TASK_H
#define TASK_H

typedef void (*task_function_t)(void);

typedef struct
{
    task_function_t task;

    int period_ticks;

    int elapsed_ticks;

} task_t;

#endif
