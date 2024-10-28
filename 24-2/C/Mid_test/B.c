#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void draw_cross(unsigned int *mat, int row, int col)
{
    // 이 위로 수정 금지
    for (int i = 0; i < 8; i++)
    {
    }
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[])
{
    unsigned int mat[8][8] = {0};
    int n, m;
    scanf("%d%d", &n, &m);

    draw_cross((unsigned int *)mat, n, m);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d%c", mat[i][j], j == 7 ? '\n' : ' ');
        }
    }

    return 0;
}