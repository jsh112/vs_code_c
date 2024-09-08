// // 문제 Q : 배열 돌리기

// 문제 설명
// 5x5크기의 2차원 배열 A와 배열을 돌릴 횟수
// N을 입력하면 A를 N번 시계방향으로 돌린 결과를 출력하시오.
// 1번 시계방향으로 돌리는 건 90도 돌리는 것이다.
// 입력 설명

// 5*5행렬의 요소 Aij
// N

// Aij(정수): 5*5 행렬의 요소
// N(정수) : 배열을 시계방향으로 돌릴 횟수
// 0 <= Aij < 2^32 (1 <= i,j <= 5)
// 0 <= N < 2^32

// 출력 설명
// A를 N번 시계방향으로 돌린 결과를 출력한다.
// 입력 예시
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15
// 16 17 18 19 20
// 21 22 23 24 25
// 1
// 출력 예시
// 21 16 11 6 1
// 22 17 12 7 2
// 23 18 13 8 3
// 24 19 14 9 4
// 25 20 15 10 5

// ACCEPTED CODE

#include <stdio.h>

int main()
{

    int N = 5;
    unsigned int matrix_ori[N][N], matrix_cpy[N][N], rotate;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%u", &matrix_ori[i][j]);
            matrix_cpy[i][j] = matrix_ori[i][j];
        }
    }
    scanf("%u", &rotate);
    rotate %= 4;
    // [0][0~N-1] -> [0~N-1][0]
    for (int r = 0; r < rotate; r++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                matrix_cpy[i][j] = matrix_ori[N - 1 - j][i];
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                matrix_ori[i][j] = matrix_cpy[i][j];
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%u ", matrix_cpy[i][j]);
        }
        printf("\n");
    }

    return 0;
}