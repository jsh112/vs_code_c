// // 문제 K : 많이 입력한 정수 찾기

// 문제 설명
// 입력한 정수 N개 중 가장 많이 입력한 정수를 출력한다.
// 단, N은 카운트하지 않는다.
// 입력 설명

// N
// A1 A2 ... AN

// N(정수): 처리할 정수의 개수 (0 <= N < 2^32)
// Ai(정수): 처리할 정수들 0 <= Ai < 101 (1 <= i <= N)

// 출력 설명
// 가장 많이 입력한 정수를 출력한다.
// 단, 입력한 횟수가 같은 경우 더 작은 정수를 출력한다.
// 입력 예시
// 4
// 1 1 2 2

// 출력 예시
// 1

// ACCEPTED CODE

#include <stdio.h>

int main()
{
    unsigned int N;
    scanf("%u", &N);
    int num;
    unsigned int A[101] = {0};
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        A[num]++;
    }
    int max = 0;
    for (int i = 1; i < 101; i++)
    {
        if (A[max] < A[i])
        {
            max = i;
        }
    }
    printf("%u\n", max);

    return 0;
}