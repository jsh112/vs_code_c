#include <stdio.h>

// 1부터 N까지 숫자 중에 2를 포함한 숫자들만의 합을 출력하는 프로그램

int main()
{
    // 양의 정수 N
    int N, cnt = 0;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int tmp = i;
        while (tmp != 0)
        {
            if (tmp % 10 == 2)
            {
                cnt += i;
                printf("%d\n", i);
            }
            tmp = tmp / 10;
        }
    }
    printf("%d\n", cnt);
    return 0;
}