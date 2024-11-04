#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ (5)

void draw_cross(unsigned int *mat, int row, int col)
{
    // 이 위로 수정 금지
    /*
     * (N, 0~M-1) -> 1
     * (0~N-1, M) -> 1
    */
    for(int i=0;i<SZ;i++){
        mat[SZ*row + i] = 1;
    }
    for(int i=0;i<SZ;i++){
        mat[col + i * SZ] = 1;
    }
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[])
{
    unsigned int mat[SZ][SZ] = {0};
    int N, M;
    scanf("%d%d", &N, &M);

    draw_cross((unsigned int *)mat, N, M);

    for (int i = 0; i < SZ; i++)
    {
        for (int j = 0; j < SZ; j++)
        {
            printf("%d%c", mat[i][j], j == SZ - 1 ? '\n' : ' ');
        }
    }

    return 0;
}