#include <stdio.h>

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);
    int card[n];
    int sum = 0;
    int near_m = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &card[i]);
    }

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                sum = card[i] + card[j] + card[k];
                if (near_m <= sum && sum <= m)
                {
                    near_m = sum;
                }
            }
        }
    }
    printf("%d\n", near_m);

    return 0;
}