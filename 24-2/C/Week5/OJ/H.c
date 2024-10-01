#include <stdio.h>

int main()
{

    // int p, std = 0x1000;
    // scanf("%x", &p);
    // int i = (p - std) / (sizeof(int) * 30);
    // p -= i * 30 * sizeof(int);
    // int j = (p - std) / (sizeof(int) * 5);
    // p -= j * 5 * sizeof(int);
    // int k = (p - std) / sizeof(int);
    // if (j == 6)
    // {
    //     j = 0;
    // }
    // if (k == 5)
    // {
    //     k = 0;
    // }
    // printf("%d %d %d", i, j, k);

    int p, std = 0x1000;
    scanf("%x", &p);

    p -= std;
    int i = p / (sizeof(int) * 30);
    p %= (sizeof(int) * 30);

    int j = p / (sizeof(int) * 5);
    p %= (sizeof(int) * 5);

    int k = p / sizeof(int);

    printf("%d %d %d", i, j, k);

    return 0;
}