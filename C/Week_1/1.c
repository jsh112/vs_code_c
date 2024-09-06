#include <stdio.h>

int main()
{
    unsigned int a;
    scanf("%u", &a);

    a = a & 0xFFFFFFFE;

    printf("%u", a);

    return 0;
}