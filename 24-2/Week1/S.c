// 문제 S : 케이크 자르기 3

// 문제 설명
// 입력한 2차원 케이크를 4등분하여 출력한다.
// 입력 설명

// Aij(정수): 6*6 행렬의 요소
// 0 <= Aij < 2^32 (1 <= i,j <= 6)

// 출력 설명
// 케이크를 더하기 모양으로 정확히 자른 모양으로 출력한다.
// 각 행의 요소들은 띄어쓰기로 구분하고, 행끼리는 줄바꿈으로 구분한다.
// 입력 예시
// 1 2 1 2 3 1
// 2 3 1 2 3 2
// 1 2 3 5 3 2
// 2 1 3 4 5 1
// 2 1 3 5 4 3
// 2 1 3 4 1 2

// 출력 예시
// 1 2 1  2 3 1
// 2 3 1  2 3 2
// 1 2 3  5 3 2

// 2 1 3  4 5 1
// 2 1 3  5 4 3
// 2 1 3  4 1 2

// ACCEPTED CODE

#include <stdio.h>

int main()
{

    const int N = 6;
    unsigned int matrix[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%u", &matrix[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i == 3)
        {
            printf("\n");
        }
        for (int j = 0; j < N; j++)
        {
            printf("%u ", matrix[i][j]);
            if (j == 2)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}