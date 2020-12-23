#include "fun_list.h"

FunList *funCreateList()
{
    FunList *head = funMalloc(sizeof(*head));
    head->type_flag = FUN_TYPE_LIST;
    head->type_name = "List";
    head->value = NULL;
    head->next = NULL;
    return head;
}

int funIsObjectList(FunObject *obj)
{
    return obj->type_flag & FUN_TYPE_LIST;
}
