#include <stdio.h>

int main()
{

    const int n = 5;
    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp = arr[i][j];
            arr[i][j] = arr[n - 1 - i][j];
            arr[n - 1 - i][j] = tmp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 2)
            {
                arr[i][j] = 5;
            }
            else if (arr[i][j] == 5)
            {
                arr[i][j] = 2;
            }
            else if (arr[i][j] == 6)
            {
                arr[i][j] = 9;
            }
            else if (arr[i][j] == 9)
            {
                arr[i][j] = 6;
            }
            else if (arr[i][j] == 8 || arr[i][j] == 1 || arr[i][j] == 3)
            {
                continue;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}