#include "Math.h"
#include<string.h>
#include<cstdarg>

int Math::Add(int x, int y) {
    return x + y;
}
int Math::Add(int x, int y, int z) {
    return x + y + z;
}

int Math::Add(double x, double y) {
    return x + y;
}

int Math::Add(double x, double y, double z) {
    return x + y + z;
}
int Math::Mul(int x, int y) {
    return x * y;
}

int Math::Mul(int x, int y, int z) {
    return x * y * z;
}
int Math::Mul(double x, double y) {
    return x * y;
}

int Math::Mul(double x, double y, double z) {
    return x * y * z;
}
int Math::Add(int count, ...) {
    int s = 0, i;
    va_list x;
    va_start(x, count);
    for (i = 1; i <= count; i++)
    {
        s = s + va_arg(x, int);
    }
    va_end(x);
    return s;

}
char* Math::Add(const char* str1, const char* str2) {
    if (!str1 || !str2) {
        return nullptr;
    }

    char* newstr = new char[strlen(str1) + strlen(str2) + 2];
    strcpy(newstr, str1);
    strcat(newstr, str2);
    return newstr;
}