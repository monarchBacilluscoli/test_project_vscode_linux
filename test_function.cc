#include "test_function.h"
#include <stdio.h>

#define PrintVarNo(i) printf(""             \
                             "var" #i "=%d" \
                             "",            \
                             var##i) // 它真的会把这个字符串加在一起去
#define PrintConcrete(x, y) printf(#x#y)

void A ::Hi()
{
    int var88 = 168;
    PrintVarNo(88);
    PrintConcrete(a, b);
    std::cout << "A" << std::endl;
}
