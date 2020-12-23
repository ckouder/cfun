#include "fun_io.h"

int main()
{
    for (;;) {
        printf(">>> ");
        FunObject *obj;
        funScanObject(&obj);
        funPrintObject(obj);
        putchar('\n');
    }
    return 0;
}
