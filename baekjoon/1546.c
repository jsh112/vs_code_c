#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int score[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &score[i]);
    }

    int max = score[0];
    for (int i = 1; i < n; i++)
    {
        if (max < score[i])
        {
            max = score[i];
        }
    }

    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += (double)score[i] / max * 100;
    }

    printf("%f\n", sum / n);

    return 0;
}