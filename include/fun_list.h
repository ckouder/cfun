#ifndef FUN_LIST_H
#define FUN_LIST_H

#include "fun_object.h"

#define FUN_TYPE_LIST 4

#define FUN_LIST_CAST(obj) ((FunList *) (obj))

typedef struct FunList {
    FUN_OBJECT_HEAD
    FunObject *value;
    struct FunList *next;
} FunList;

FunList *funCreateList();

int funIsObjectList(FunObject *obj);

#endif
