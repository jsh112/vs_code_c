#include <stdio.h>

int main()
{
    int a[32];
    for (int i = 0; i < 32; i++)
    {
        scanf("%1d", &a[i]);
    }

    for (int i = 0; i < 32; i++)
    {
        printf("%d", !a[i]);
    }
    printf("\n");
    for (int i = 0; i < 32; i++)
    {
        if (a[i])
        {
            printf("0");
            return 0;
        }
        else
        {
            continue;
        }
    }
    printf("1");

    return 0;
}