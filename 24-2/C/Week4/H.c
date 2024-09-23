#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    unsigned int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%u", &a[i]);
    }
    unsigned int t;
    scanf("%u", &t);

    int q = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] <= t)
        {
            printf("%d ", q);
        }
        else
        {
            printf("%u ", a[j]);
        }
    }
    return 0;
}