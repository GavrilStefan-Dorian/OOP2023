
#include <stdio.h>
using namespace std;
int transformare(char* s)
{
    int n = 0;
    while (*s >= '0' && *s <= '9')
    {
        n = n * 10 + (*s - '0');
        s++;
    }
    return n;
}
int main()
{
    FILE* fp;
    char numar[100];
    int sum = 0;
    fp = fopen("in.txt", "r");
    if (fp == 0)
    {
        printf("Eroare deschidere fisier\n");
        return 1;
    }

    while (fgets(numar, 100, fp) != 0)
    {
        sum = sum + transformare(numar);
    }
    fclose(fp);
    printf("%d\n", sum);
    return 0;
}