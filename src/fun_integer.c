#include "fun_integer.h"

FunInteger *funCreateInteger()
{
    FunInteger *integer = funMalloc(sizeof(*integer));
    integer->type_flag = FUN_TYPE_INTEGER;
    integer->type_name = "Integer";
    integer->value = 0;
    return integer;
}

int funIsObjectInteger(FunObject *obj)
{
    return obj->type_flag & FUN_TYPE_INTEGER;
}
