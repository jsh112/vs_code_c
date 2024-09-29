#include <stdio.h>

int main()
{

    const int n = 9;
    unsigned int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%u", &matrix[i][j]);
        }
    }

    // 대각선 , j == (n/2) or j == (n/2)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == j) || (i + j) == 8 || (i == n / 2) || (j == n / 2))
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