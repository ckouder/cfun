#ifndef FUN_VECTOR_H
#define FUN_VECTOR_H

#include "fun_object.h"

#define FUN_TYPE_VECTOR 8

#define FUN_VECTOR_CAST(obj) ((FunVector *) (obj))

typedef struct {
    FUN_RESIZABLE_OBJECT_HEAD
    FunSizeType size;
    FunObject **elems;
} FunVector;

FunVector *funCreateVector();

int funIsObjectVector(FunObject *obj);

int funPushBackInVector(FunVector *vector, FunObject *obj);

#endif
