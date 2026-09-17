#include <stddef.h>

#ifndef SILK_CORE_MEMORY_H
#define SILK_CORE_MEMORY_H

void *
silk_malloc(size_t size);

void *
silk_calloc(size_t count, size_t size);

void
silk_free(void *pointer);

#endif
