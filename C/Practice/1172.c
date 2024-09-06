#include <stdio.h>

int main()
{

    // N개의 숫자를 입력받을 때 최솟값, 최댓값을 각각 출력하는 프로그램

    int N;
    scanf("%d", &N);
    int a[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    int max = a[0], min = a[0];
    for (int i = 0; i < N - 1; i++)
    {
        if (max <= a[i + 1])
        {
            max = a[i + 1];
        }
        else if (min >= a[i + 1])
        {
            min = a[i + 1];
        }
    }

    printf("%d %d", min, max);

    // for (int i = 0; i < N; i++)
    // {
    //     printf("%d ", a[i]);
    // }

    return 0;
}