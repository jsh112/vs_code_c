#include <stdio.h>

int main()
{

    int N;
    scanf("%d", &N);
    unsigned int a[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%u", &a[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((i + j) == N - 1)
            {
                printf("  ");
            }
            else
            {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}