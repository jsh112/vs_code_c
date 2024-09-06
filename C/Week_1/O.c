#include <stdio.h>

int main()
{

    unsigned int n;
    int cnt = 0;
    unsigned int a[5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%u", &a[i][j]);
        }
    }

    scanf("%u", &n);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (a[i][j] >= n)
            {
                cnt++;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}