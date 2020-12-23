#ifndef FUN_INTEGER
#define FUN_INTEGER

#include "fun_object.h"

#define FUN_TYPE_INTEGER 1

#define FUN_INTEGER_CAST(obj) ((FunInteger *) (obj))

typedef struct {
    FUN_OBJECT_HEAD
    long value;
} FunInteger;

FunInteger *funCreateInteger();

int funIsObjectInteger(FunObject *obj);

#endif
