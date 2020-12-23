#ifndef FUN_MEMORY_H
#define FUN_MEMORY_H

#include <stdlib.h>

void *funMalloc(size_t size);

void funFree(void *ptr);

void *funRealloc(void *ptr, size_t new_size);

#endif
