#include <stdio.h>

int main()
{
    // 세 숫자 입력받아서 절댓값 기준
    // 가장 큰 수와 중간수 차이, 중간수와 최솟값 차이 출력

    int a, b, c, max, mid, min;
    scanf("%d %d %d", &a, &b, &c);

    if (a < 0)
    {
        a = -a;
    }
    if (b < 0)
    {
        b = -b;
    }
    if (c < 0)
    {
        c = -c;
    }

    if ((a >= b) && (a >= c))
    {
        max = a;
        if (b >= c)
        {
            mid = b;
            min = c;
        }
        else
        {
            mid = c;
            min = b;
        }
    }
    else if ((b >= a) && (b >= c))
    {
        max = b;
        if (a >= c)
        {
            mid = a;
            min = c;
        }
        else
        {
            mid = c;
            min = a;
        }
    }
    else
    {
        max = c;
        if (a >= b)
        {
            mid = a;
            min = b;
        }
        else
        {
            mid = b;
            min = a;
        }
    }
    printf("%d %d", max - mid, mid - min);
    return 0;
}