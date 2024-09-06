#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int matrix[n][n];

    // 4면 두겹, 5면 세겹, 6은 3겹, ...
    // 홀수가 (n+1)/2라 하면 짝수도 성립하므로
    // 겹은 (n+1)/2로 정하자
    // 홀수는 핵이 있고, 짝수는 핵이 없음
    // 가장 안쪽 값은 항상 N부터 시작(짝수는 N이 2x2로 핵을 이룸)

    int layer = (n + 1) / 2;
    for (int i = 0; i < layer; i++)
    {
        int num = n - i;
        for (int j = i; j < n - i; j++)
        {
            // 상, 하, 좌, 우
            matrix[i][j] = num;
            matrix[num - i - 1][j] = num;
            matrix[j][i] = num;
            matrix[j][num - i - 1] = num;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}