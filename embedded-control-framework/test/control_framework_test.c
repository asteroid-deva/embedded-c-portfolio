#include <stdio.h>

#include "fsm.h"

int main(void)
{
    system_state_t state =
        STATE_INIT;

    system_event_t events[] =
    {
        EVT_BOOT_COMPLETE,
        EVT_ARM,
        EVT_START,
        EVT_FAULT,
        EVT_RECOVER,
        EVT_RECOVERY_DONE
    };

    int count =
        sizeof(events) /
        sizeof(events[0]);

    printf("Embedded Control Framework Test\n\n");

    for(int i = 0; i < count; i++)
    {
        printf("State: %s -> ",
               state_to_str(state));

        state =
            fsm_handle_event(
                state,
                events[i]);

        printf("%s\n",
               state_to_str(state));
    }

    return 0;
}
