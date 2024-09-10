#include <stdio.h>

int main()
{
    const int n = 10;
    unsigned int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%u", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%u ", (a[i]));
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%u ", (a[i] + 1));
    }
    return 0;
}