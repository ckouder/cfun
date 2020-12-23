#include "fun_io.h"

int funScanInteger(FunInteger *integer)
{
    scanf("%ld", &integer->value);
    return 0;
}

int funPrintInteger(FunInteger *integer)
{
    printf("%ld", integer->value);
    return 0;
}

int funIsCharDelimiter(char c)
{
    return c == ')' || c == ']' || c == '}'
        || c == ',' || c == ':' || c == '.';
}

int funScanSymbol(FunSymbol *symbol)
{
    char c;
    while (!isspace(c = getchar())) {
        if (funIsCharDelimiter(c)) {
            ungetc(c, stdin);
            return 0;
        }
        funPushBackInSymbol(symbol, c);
    }
    return 0;
}

int funPrintSymbol(FunSymbol *symbol)
{
    for (FunSizeType i = 0; i < symbol->size; ++i) {
        putchar(symbol->str[i]);
    }
    return 0;
}

int funScanList(FunList *head)
{
    FunList *node = head;
    char c;
    while (scanf(" %c", &c) && c != ')') {
        ungetc(c, stdin);
        funScanObject(&node->value);
        node->next = funCreateList();
        node = node->next;
    }
    return 0;
}

int funPrintList(FunList *head)
{
    if (head->value == NULL) {
        printf("()");
        return 0;
    }
    putchar('(');
    funPrintObject(head->value);
    FunList *node = head->next;
    while (node->value != NULL) {
        putchar(' ');
        funPrintObject(node->value);
        node = node->next;
    }
    putchar(')');
    return 0;
}

int funScanVector(FunVector *vector)
{
    char c;
    while (scanf(" %c", &c) && c != ']') {
        ungetc(c, stdin);
        FunObject *obj;
        funScanObject(&obj);
        funPushBackInVector(vector, obj);
    }
    return 0;
}

int funPrintVector(FunVector *vector)
{
    if (vector->size == 0) {
        printf("[]");
        return 0;
    }
    putchar('[');
    funPrintObject(vector->elems[0]);
    for (FunSizeType i = 1; i < vector->size; ++i) {
        putchar(' ');
        funPrintObject(vector->elems[i]);
    }
    putchar(']');
    return 0;
}

int funScanObject(FunObject **obj)
{
    char c;
    scanf(" %c", &c);
    if (c == '(') {
        FunList *head = funCreateList();
        funScanList(head);
        *obj = FUN_OBJECT_CAST(head);
    } else if (c == '[') {
        FunVector *vector = funCreateVector();
        funScanVector(vector);
        *obj = FUN_OBJECT_CAST(vector);
    } else if (isdigit(c)) {
        ungetc(c, stdin);
        FunInteger *integer = funCreateInteger();
        funScanInteger(integer);
        *obj = FUN_OBJECT_CAST(integer);
    } else {
        ungetc(c, stdin);
        FunSymbol *symbol = funCreateSymbol();
        funScanSymbol(symbol);
        *obj = FUN_OBJECT_CAST(symbol);
    }
    return 0;
}

int funPrintObject(FunObject *obj)
{
    if (funIsObjectInteger(obj)) {
        return funPrintInteger(FUN_INTEGER_CAST(obj));
    }
    if (funIsObjectSymbol(obj)) {
        return funPrintSymbol(FUN_SYMBOL_CAST(obj));
    }
    if (funIsObjectList(obj)) {
        return funPrintList(FUN_LIST_CAST(obj));
    }
    if (funIsObjectVector(obj)) {
        return funPrintVector(FUN_VECTOR_CAST(obj));
    }
    return 0;
}
