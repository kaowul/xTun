
#include <stdlib.h>
#include <string.h>

#include "buffer.h"
#include "util.h"

int
buffer_alloc(buffer_t *ptr, size_t capacity) {
    memset(ptr, 0, sizeof *ptr);
    ptr->data = malloc(capacity);
    ptr->capacity = capacity;
    return capacity;
}

int
buffer_realloc(buffer_t *buf, size_t len, size_t capacity) {
    if (buf == NULL) {
        return -1;
    }
    size_t rc = max(len, capacity);
    if (buf->capacity < rc) {
        buf->data = realloc(buf->data, rc);
        buf->capacity = rc;
    }
    return rc;
}

void
buffer_free(buffer_t *buf) {
    if (buf == NULL) {
        return;
    }
    buf->off = 0;
    buf->len = 0;
    buf->capacity = 0;
    if (buf->data != NULL) {
        free(buf->data);
    }
}