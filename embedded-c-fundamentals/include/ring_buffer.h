#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

/*
 * Fixed-size ring buffer for embedded systems.
 * Designed for deterministic behavior and static allocation.
 */

typedef struct {
    uint8_t *buffer;     // Pointer to user-provided storage
    uint16_t size;       // Total size of the buffer
    uint16_t head;       // Write index
    uint16_t tail;       // Read index
    bool full;           // Buffer full flag
} ring_buffer_t;

/* Initialize ring buffer with user-provided memory */
void ring_buffer_init(ring_buffer_t *rb, uint8_t *storage, uint16_t size);

/* Write one byte into the buffer */
bool ring_buffer_put(ring_buffer_t *rb, uint8_t data);

/* Read one byte from the buffer */
bool ring_buffer_get(ring_buffer_t *rb, uint8_t *data);

/* Check if buffer is empty */
bool ring_buffer_is_empty(const ring_buffer_t *rb);

/* Check if buffer is full */
bool ring_buffer_is_full(const ring_buffer_t *rb);

/* Clear buffer contents */
void ring_buffer_reset(ring_buffer_t *rb);

#endif /* RING_BUFFER_H */
