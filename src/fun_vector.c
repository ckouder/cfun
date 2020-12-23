#include "fun_vector.h"

FunVector *funCreateVector()
{
    FunVector *vector = funMalloc(sizeof(*vector));
    vector->type_flag = FUN_TYPE_VECTOR;
    vector->type_name = "Vector";
    vector->capacity = 1;
    vector->size = 0;
    vector->elems = funMalloc(vector->capacity * sizeof(*vector->elems));
    return vector;
}

int funIsObjectVector(FunObject *obj)
{
    return obj->type_flag & FUN_TYPE_VECTOR;
}

int funPushBackInVector(FunVector *vector, FunObject *obj)
{
    if (vector->size >= vector->capacity) {
        vector->capacity *= 2;
        vector->elems = funRealloc(
            vector->elems, vector->capacity * sizeof(*vector->elems));
    }
    vector->elems[vector->size] = obj;
    ++vector->size;
    return 0;
}
