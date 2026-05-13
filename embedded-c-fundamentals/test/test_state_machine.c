#include <stdio.h>
#include <assert.h>
#include "state_machine.h"

int main(void)
{
    state_machine_t sm;

    /* Initialize */
    state_machine_init(&sm);
    assert(state_machine_get_state(&sm) == STATE_IDLE);

    /* Illegal: IDLE -> ACTIVE */
    assert(state_machine_handle_event(&sm, EVENT_START) == false);
    assert(state_machine_get_state(&sm) == STATE_IDLE);

    /* IDLE -> ARMED */
    assert(state_machine_handle_event(&sm, EVENT_ARM) == true);
    assert(state_machine_get_state(&sm) == STATE_ARMED);

    /* ARMED -> ACTIVE */
    assert(state_machine_handle_event(&sm, EVENT_START) == true);
    assert(state_machine_get_state(&sm) == STATE_ACTIVE);

    /* ACTIVE -> FAILSAFE */
    assert(state_machine_handle_event(&sm, EVENT_SIGNAL_LOST) == true);
    assert(state_machine_get_state(&sm) == STATE_FAILSAFE);

    /* Illegal: FAILSAFE -> ACTIVE */
    assert(state_machine_handle_event(&sm, EVENT_START) == false);
    assert(state_machine_get_state(&sm) == STATE_FAILSAFE);

    /* FAILSAFE -> IDLE */
    assert(state_machine_handle_event(&sm, EVENT_SIGNAL_RESTORED) == true);
    assert(state_machine_get_state(&sm) == STATE_IDLE);

    printf("State machine tests passed.\n");
    return 0;
}
