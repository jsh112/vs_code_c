#include <stdio.h>

// 두 수를 입력 받아 큰 수에서 작은 수 빼기

int main()
{

    int N, M;
    scanf("%d %d", &N, &M);

    if (N < M)
    {
        int tmp = N;
        N = M;
        M = tmp;
    }
    printf("%d\n", N - M);

    return 0;
}