#include "fun_symbol.h"

FunSymbol *funCreateSymbol()
{
    FunSymbol *symbol = funMalloc(sizeof(*symbol));
    symbol->type_flag = FUN_TYPE_SYMBOL;
    symbol->type_name = "Symbol";
    symbol->capacity = 1;
    symbol->size = 0;
    symbol->str = funMalloc(symbol->capacity * sizeof(*symbol->str));
    return symbol;
}

int funIsObjectSymbol(FunObject *obj)
{
    return obj->type_flag & FUN_TYPE_SYMBOL;
}

int funPushBackInSymbol(FunSymbol *symbol, char c)
{
    if (symbol->size >= symbol->capacity) {
        symbol->capacity *= 2;
        symbol->str = funRealloc(
            symbol->str, symbol->capacity * sizeof(*symbol->str));
    }
    symbol->str[symbol->size] = c;
    ++symbol->size;
    return 0;
}
