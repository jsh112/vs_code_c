#include <stdio.h>

char a = 2, b = 7;

int main()
{

    // for (int i = 1; i < 9; i++)
    // {
    //     for (int j = 2; j < 7; j++)
    //     {
    //         printf("%d *  %d = %2d   ", j, i, (i * j));
    //     }
    //     printf("\n");
    // }

    int i, j;
    for (i = 1; i < 9; i++, a = 2)
    {
        for (j = 2; j < b; j++, a++)
        {
            printf("%2d * %2d = %2d    ", j, i, j * i);
        }
        printf("\n");
    }

    return 0;
}