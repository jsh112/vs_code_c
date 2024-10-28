#include <stdio.h>

int main()
{

    unsigned int a, b;
    scanf("%X %X", &a, &b);

    unsigned int _a = (a & (0xFF << 3 * 8));
    unsigned int _b = (b & (0xFF << 3 * 8));

    a = (a << 8) >> 8;
    b = (b << 8) >> 8;

    a |= _b;
    b |= _a;

    printf("%X와 %X", a, b);

    return 0;
}