#include <stdio.h>
#include <cstring>

int main()
{
    char cuvinte[256], a[256][256], aux[256];
    char* p;
    scanf("%[^\n]", cuvinte);
    getchar(); 

    int cnt = 0, i, j;
    p = strtok(cuvinte, " ");
    while (p)
    {
        strcpy(a[cnt], p);
        cnt++;
        p = strtok(NULL, " ");
    }
    for (i = 0; i < cnt; i++)
        for (j = i + 1; j < cnt; j++)
        {
            if (strlen(a[i]) < strlen(a[j]))
            {
                strcpy(aux, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], aux);
            }
            if (strlen(a[i]) == strlen(a[j]))
            {
                if (strcmp(a[i], a[j]) > 0)
                {
                    strcpy(aux, a[i]);
                    strcpy(a[i], a[j]);
                    strcpy(a[j], aux);
                }
            }
        }
    for (i = 0; i < cnt; i++)
        printf("%s\n", a[i]);
    return 0;
}