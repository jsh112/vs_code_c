#include <stdio.h>

int main()
{

    unsigned int a;
    // 0x0 <= A < 0x100
    // %X가 4바이트를 읽어옴
    scanf("%X", &a);
    for (int i = 7; i >= 4; i--)
    {
        printf("%d", (a >> i) & 0x01);
    }
    printf(" ");
    // 1110 0111
    for (int j = 4; j < 8; j++)
    {
        printf("%d", (a >> j) & 0x01);
    }

    return 0;
}