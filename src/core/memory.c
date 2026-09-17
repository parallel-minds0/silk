#include "core/memory.h"

#include <stdlib.h>

void *
silk_malloc(size_t size)
{
	return malloc(size);
}

void *
silk_calloc(size_t count, size_t size)
{
	return calloc(count, size);
}

void
silk_free(void *pointer)
{
	free(pointer);
}
