#include <stdio.h>

int main()
{

    const int sz = 11;
    int arr[sz][sz];
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    // printf("\n\n");
    // for (int i = 0; i < sz; i++)
    // {
    //     for (int j = 0; j < sz; j++)
    //     {
    //         printf("%d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    int sum = 0;
    int _i, _j;
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            if (arr[i][j] != 0)
            {
                _i = (i >= 5) ? (i - 5) : (5 - i);
                _j = (j >= 5) ? (j - 5) : (5 - j);

                _i = (_i > _j) ? _i : _j;
                sum += (5 - _i) * arr[i][j];
            }
        }
    }
    printf("%d", sum);

    return 0;
}