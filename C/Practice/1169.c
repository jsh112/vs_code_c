#include <stdio.h>

int main()
{

    // 세 개의 숫자를 입력받아 가장 큰 수와 중간 숫자 간의 차이
    // 중간 숫자와 제일 작은 숫자간의 차이를 출력하는 프로그램을 작성하시오.

    int a, b, c;
    int min, mid, max;
    scanf("%d %d %d", &a, &b, &c);
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