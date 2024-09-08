#include <stdio.h>

int main()
{
    long n;
    scanf("%ld", &n);
    for (long i = 0; i < n; i++)
    {
        if ((n <= 3 * i * (i + 1) + 1) && (n >= 3 * i * (i - 1) + 1))
        {
            printf("%d", i + 1);
            break;
        }
        if ((n < 3 * i * (i - 1) + 1))
        {
            break;
        }
    }

    return 0;
}