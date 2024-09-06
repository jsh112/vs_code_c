#include <stdio.h>

int main()
{
    long a, b, c, max, mid, min;

    while (1)
    {
        scanf("%ld %ld %ld", &a, &b, &c);
        if ((a == 0) && (b == 0) && (c == 0))
            break;
        else
        {
            if ((a >= b) && (a >= c))
            {
                max = a;
                mid = b;
                min = c;
            }
            else if ((b >= c) && (b >= a))
            {
                max = b;
                mid = a;
                min = c;
            }
            else if ((c >= a) && (c >= b))
            {
                max = c;
                mid = b;
                min = a;
            }
            else if (max >= mid + min)
            {
                break;
            }

            if (max * max == min * min + mid * mid)
            {
                printf("right\n");
            }
            else
            {
                printf("wrong");
            }
        }
    }

    return 0;
}