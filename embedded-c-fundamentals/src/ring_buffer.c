#include "ring_buffer.h"

static void advance_pointer(ring_buffer_t *rb)
{
    if (rb->full) {
        rb->tail = (rb->tail + 1) % rb->size;
    }

    rb->head = (rb->head + 1) % rb->size;
    rb->full = (rb->head == rb->tail);
}

static void retreat_pointer(ring_buffer_t *rb)
{
    rb->full = false;
    rb->tail = (rb->tail + 1) % rb->size;
}

void ring_buffer_init(ring_buffer_t *rb, uint8_t *storage, uint16_t size)
{
    rb->buffer = storage;
    rb->size = size;
    rb->head = 0;
    rb->tail = 0;
    rb->full = false;
}

bool ring_buffer_put(ring_buffer_t *rb, uint8_t data)
{
    if (!rb || !rb->buffer) {
        return false;
    }

    rb->buffer[rb->head] = data;
    advance_pointer(rb);
    return true;
}

bool ring_buffer_get(ring_buffer_t *rb, uint8_t *data)
{
    if (!rb || !data || ring_buffer_is_empty(rb)) {
        return false;
    }

    *data = rb->buffer[rb->tail];
    retreat_pointer(rb);
    return true;
}

bool ring_buffer_is_empty(const ring_buffer_t *rb)
{
    return (!rb->full && (rb->head == rb->tail));
}

bool ring_buffer_is_full(const ring_buffer_t *rb)
{
    return rb->full;
}

void ring_buffer_reset(ring_buffer_t *rb)
{
    rb->head = 0;
    rb->tail = 0;
    rb->full = false;
}
