#include <stdio.h>

int main()
{
    int a, b, r;
    scanf("%d %d", &a, &b);
    if (a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    int max = 1;
    for (int i = 1; i <= b; i++)
    {
        if ((a % i) == 0 && (b % i) == 0)
        {
            if (max < i)
            {
                max = i;
            }
        }
    }
    printf("%d\n", max);

    return 0;
}