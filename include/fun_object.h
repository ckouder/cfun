#ifndef FUN_OBJECT_H
#define FUN_OBJECT_H

#include <stddef.h>

#include "fun_memory.h"

#define FUN_OBJECT_HEAD                         \
    int type_flag;                              \
    const char *type_name;

#define FUN_RESIZABLE_OBJECT_HEAD               \
    FUN_OBJECT_HEAD                             \
    FunSizeType capacity;

#define FUN_OBJECT_CAST(obj) ((FunObject *) (obj))

typedef size_t FunSizeType;

typedef struct {
    FUN_OBJECT_HEAD
} FunObject;

typedef struct {
    FUN_OBJECT_HEAD
    FunSizeType size;
} FunResizableObject;

#endif
