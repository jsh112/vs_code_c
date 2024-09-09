// 문제 P : 모자이크

// 문제 설명
// 배열의 크기 N만큼 모자이크를 출력하시오.
// 입력 설명

// N

// N(정수) : 출력할 모자이크의 크기
// 0 < N < 50

// 출력 설명
// N * N크기의 2차원 배열을 출력한다.
// 단, N이 홀수일 경우 1로 시작하고 짝수일 경우 0으로 시작한다.
// 입력 예시
// 5

// 출력 예시
// 1 0 1 0 1
// 0 1 0 1 0
// 1 0 1 0 1
// 0 1 0 1 0
// 1 0 1 0 1

// ACCEPTED CODE

#include <stdio.h>

int main()
{

    int N;
    scanf("%d", &N);
    int matrix[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((i + j + N) % 2 != 0)
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

    return 0;
}