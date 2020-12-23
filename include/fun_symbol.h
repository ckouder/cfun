#ifndef FUN_SYMBOL_H
#define FUN_SYMBOL_H

#include "fun_object.h"

#define FUN_TYPE_SYMBOL 2

#define FUN_SYMBOL_CAST(obj) ((FunSymbol *) (obj))

typedef struct {
    FUN_RESIZABLE_OBJECT_HEAD
    FunSizeType size;
    char *str;
} FunSymbol;

FunSymbol *funCreateSymbol();

int funIsObjectSymbol(FunObject *obj);

int funPushBackInSymbol(FunSymbol *symbol, char c);

#endif
