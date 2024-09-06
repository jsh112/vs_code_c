#include <stdio.h>

int main(void)
{
    // 모서리
    // 크기가 N x N이라면
    // a[0][0~N-1] = 0
    // a[N-1][0~N-1] = 0
    // a[0~N-1][0] = 0
    // a[0~N-1][N-1] = 0

    int n;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        a[0][i] = 0;
        a[n - 1][i] = 0;
        a[i][0] = 0;
        a[i][n - 1] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}