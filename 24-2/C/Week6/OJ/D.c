#include <stdio.h>

int main()
{

    unsigned int n;
    scanf("%X", &n);

    unsigned int a, b, c, d;

    a = (n >> 8 * 2) & 0xFF;
    b = (n >> 8 * 3) & 0xFF;
    if (b == 0)
    {
        printf("%X", a);
        printf("00");
    }
    else if (a != 0 && b != 0)
    {
        printf("%X%X", a, b);
    }
    a = n & 0xFF;
    b = (n >> 8 * 1) & 0xFF;
    if (a == 0)
    {
        printf("00%X", b);
    }
    else if (b == 0)
    {
        printf("%X", a);
        printf("00");
    }
    else
    {
        printf("%X%X", a, b);
    }

    return 0;
}