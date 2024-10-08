// 문제 R : 주대각행렬

// 문제 설명
// 5*5 크기의 2차원 배열을 입력한다.
// 왼쪽 위와 오른쪽 아래쪽을 잇는 대각선 요소들을 전부 0으로 바꾸어 출력한다.
// 입력 설명
// 5*5 행렬의 요소들

// Aij(정수): 5*5 행렬의 요소
// 0 <= Aij < 2^32 (1 <= i,j <= 5)

// 출력 설명
// 대각선 요소에 해당하는 요소를 0으로 바꾸어 5*5 크기로 출력한다.
// 각 행의 요소들은 띄어쓰기로 구분하고, 행끼리는 줄바꿈으로 구분한다.

// 입력 예시
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5

// 출력 예시
// 0 2 3 4 5
// 1 0 3 4 5
// 1 2 0 4 5
// 1 2 3 0 5
// 1 2 3 4 0

// ACCEPTED CODE

#include <stdio.h>

int main()
{
    const int N = 5;
    unsigned int matrix[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%u", &matrix[i][j]);
            if (i == j)
            {
                matrix[i][j] = 0;
            }
            printf("%u ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}