#include <stdio.h>

// 비트연산

int main()
{

    int n, iter = 8;
    int a[iter], k = 1, sum = 0;
    scanf("%d", &n);
    // for (int i = 0; i < 8; i++)
    // {
    //     if (i == 0 || i == 3 || i == 4 || i == 7)
    //     {
    //         a[i] = 0;
    //     }
    //     else
    //     {
    //         a[i] = (n >> i) & 0x01;
    //     }
    //     sum += k * a[i];
    //     k *= 2;
    // }

    // printf("%d\n", sum);
    // 0110 0110 -> 0x66
    printf("%d\n", n & 0x66);
    return 0;
}