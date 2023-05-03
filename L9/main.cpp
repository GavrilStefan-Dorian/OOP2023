//operator[] ,op=
//struct cu int cc*
//op= caz key exista



#include "Map.h"
#include <iostream>

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";//ctor for Pair?
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}