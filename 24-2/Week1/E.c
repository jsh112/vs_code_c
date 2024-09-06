// 문제 E : 케이크 자르기2
// 문제 설명
// 입력한 2차원 케이크를 2등분하여 출력한다.
// 근데, 자른 부분은 으깨져서 보이지 않는다.

// N : Size of matrix, 1<=N<101
// A(i,j) : N by N의 요소들, 0<=A<2^32

// 출력 설명
// 케이크를 / 모양으로 정확히 자른 모양으로 출력한다.
// 각 행의 요소들은 띄어쓰기로 구분하고, 행끼리는 줄바꿈으로 구분한다.

// 입력 예시
// 6
// 1 2 1 2 3 1
// 2 3 1 2 3 2
// 1 2 3 5 3 2
// 2 1 3 4 5 1
// 2 1 3 5 4 3
// 2 1 3 4 1 2

// 출력 예시
// 1 2 1 2 3
// 2 3 1 2   2
// 1 2 3   3 2
// 2 1   4 5 1
// 2   3 5 4 3
//   1 3 4 1 2

#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    unsigned int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%u", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i + j) == n - 1)
            {
                printf("  ");
            }
            else
            {
                printf("%u ", matrix[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}