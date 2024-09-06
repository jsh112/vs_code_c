#include <stdio.h>

int func(int a);

int main()
{

    printf("%d", func(5));

    return 0;
}

int func(int a)
{
    int cnt = 0;
    for (int i = 1; i <= a; i++)
    {
        if (i % 3 == 0)
        {
            cnt++;
        }
    }
    return cnt;
}