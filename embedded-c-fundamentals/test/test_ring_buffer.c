#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "ring_buffer.h"

int main(void)
{
    uint8_t storage[4];
    ring_buffer_t rb;
    uint8_t data;

    ring_buffer_init(&rb, storage, sizeof(storage));

    /* Write 5 bytes into size-4 buffer */
    ring_buffer_put(&rb, 'A');
    ring_buffer_put(&rb, 'B');
    ring_buffer_put(&rb, 'C');
    ring_buffer_put(&rb, 'D');
    ring_buffer_put(&rb, 'E');  // Overwrites 'A'

    /* Read back data */
    ring_buffer_get(&rb, &data);
    assert(data == 'B');

    ring_buffer_get(&rb, &data);
    assert(data == 'C');

    ring_buffer_get(&rb, &data);
    assert(data == 'D');

    ring_buffer_get(&rb, &data);
    assert(data == 'E');

    /* Buffer should now be empty */
    assert(ring_buffer_is_empty(&rb));

    printf("Ring buffer overwrite test passed.\n");
    return 0;
}
