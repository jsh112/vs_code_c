#include <stdio.h>

int main()
{

    unsigned int a[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%u", &a[i]);
    }
    int n;
    scanf("%d", &n);
    int b[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += a[b[j]];
    }
    printf("%u\n", sum);

    return 0;
}