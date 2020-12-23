#include "fun_memory.h"

void *funMalloc(size_t size)
{
    return malloc(size);
}

void funFree(void *ptr)
{
    free(ptr);
}

void *funRealloc(void *ptr, size_t new_size)
{
    return realloc(ptr, new_size);
}
