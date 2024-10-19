#include <stdio.h>
#define SZ 11
int main()
{

    char pos[SZ][SZ];
    for (int i = 0; i < SZ; i++)
    {
        for (int j = 0; j < SZ; j++)
        {
            scanf(" %c", &pos[i][j]);
        }
    }

    int row, col, score;
    for (int i = 0; i < SZ; i++)
    {
        for (int j = 0; j < SZ; j++)
        {
            if (pos[i][j] == '@')
            {
                row = (i > 5) ? (i -= 5) : (5 - i);
                col = (j > 5) ? (j -= 5) : (5 - j);
                score = (row > col) ? row : col;
                printf("%d\n", 5 - score);
                return 0;
            }
        }
    }

    return 0;
}