#ifndef FUN_IO_H
#define FUN_IO_H

#include <ctype.h>
#include <stdio.h>

#include "fun_integer.h"
#include "fun_list.h"
#include "fun_symbol.h"
#include "fun_vector.h"

int funScanInteger(FunInteger *integer);
int funPrintInteger(FunInteger *integer);

int funIsCharDelimiter(char c);

int funScanSymbol(FunSymbol *symbol);
int funPrintSymbol(FunSymbol *symbol);

int funScanList(FunList *head);
int funPrintList(FunList *head);

int funScanVector(FunVector *vector);
int funPrintVector(FunVector *vector);

int funScanObject(FunObject **obj);
int funPrintObject(FunObject *obj);

#endif
