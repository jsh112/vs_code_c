#include <stdio.h>

int main()
{

    int i, j;
    scanf("%d %d", &i, &j);
    // 32비트, 16진수 8개
    int k = 0x1000;
    printf("%X", (i * 20 + j * 4) + k);
    return 0;
}