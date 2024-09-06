#include <stdio.h>

int main()
{

    const int N = 13;
    int b[N];
    int adult;
    int age;
    int year;
    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &b[i]);
    }

    year = 10 * b[0] + b[1];

    // 미성년 검사 대상 아님
    // 7번째 자리가 0,9,1,2,5,6이면 검사 필요 없음
    // 3, 4, 7, 8
    if ((b[6] == 3) || (b[6] == 4) || (b[6] == 7) || (b[6] == 8))
    {
        // 검사대상
        if (b[1] > 6)
        {
            adult = 0;
        }
    }

    else
    {
        adult = 1;
    }

    if (b[3] < 9)
    {
        // 1 ~ 8, 생일 지남
        if (b[2] == 0)
        {
            age = 124 - year;
            if (age >= 100)
            {
                age = age - 100;
            }
        }
        else if (b[2] == 1)
        {
            // 10, 11, 12
            age = 124 - year - 1;
            if (age >= 100)
            {
                age = age - 100;
            }
        }
    }
    else if (b[3] == 9)
    {
        if (b[4] > 3)
        {
            // 생일 안지남
            age = 124 - year - 1;
            if (age >= 100)
            {
                age = age - 100;
            }
        }
        else if (b[4] <= 3)
        {
            age = 124 - year;
            if (age >= 100)
            {
                age = age - 100;
            }
        }
    }

    if (adult == 1)
    {
        printf("%d yes", age);
    }
    else
    {
        printf("%d no", age);
    }

    return 0;
}