#include <stdio.h>

int count_zeros1(int n);
int count_zeros2(int n);

int main()
{
    int n;
    scanf("%d", &n);
    // int zeros = count_zeros1(n);
    int zeros = count_zeros2(n);
    printf("%d\n", zeros);
    return 0;
}

int count_zeros1(int n)
{
    int cnt = 0;
    for (int i = 5; i <= n; i += 5)
    {
        if (i % 125 == 0)
        {
            cnt += 3;
        }
        else if (i % 25 == 0)
        {
            cnt += 2;
        }
        else if (i % 5 == 0)
        {
            cnt++;
        }
    }
    return cnt;
}

int count_zeros2(int n)
{
    int cnt = 0;
    while (n >= 5)
    {
        n /= 5;
        cnt += n;
    }
    return cnt;
}
