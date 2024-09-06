#include <stdio.h>

int cnt_prime(int n);

int main()
{
    int N, cnt = 0;
    scanf("%d", &N);
    int a[N];
    // for (int i = 0; i < N; i++)
    // {
    //     int prime = 1;
    //     scanf("%d", &a[i]);
    //     for (int j = a[i] - 1; j > 1; j--)
    //     {
    //         if (a[i] % j == 0)
    //         {
    //             prime = 0;
    //             break;
    //         }
    //     }
    //     if (a[i] != 1 && prime)
    //         cnt++;
    // }

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        cnt += cnt_prime(a[i]);
    }
    printf("%d\n", cnt);

    return 0;
}

int cnt_prime(int n)
{
    if (n < 2)
    {
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}