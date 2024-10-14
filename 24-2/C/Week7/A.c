#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    unsigned int a[n], low, high;
    for (int i = 0; i < n; i++)
    {
        scanf("%u", &a[i]);
    }
    scanf("%u %u", &low, &high);
    for (int i = 0; i < n; i++)
    {
        if ((a[i] < low) || (a[i] > high))
        {
            printf("0 ");
        }
        else
        {
            printf("%u ", a[i]);
        }
    }

    return 0;
}