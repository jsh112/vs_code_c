#include <stdio.h>

int main()
{
    // 숫자 N(N>=2)를 입력받아 1~2까지의 합, 1~3까지의 합... 1~N까지의 합 중 홀수 출력

    int N;
    scanf("%d", &N);

    for (int i = 2; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= i; j++)
        {
            sum += j;
        }
        if (sum % 2 != 0)
        {
            printf("%d ", sum);
        }
    }

    return 0;
}