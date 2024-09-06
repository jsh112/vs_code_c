#include <stdio.h>

int main()
{

    unsigned int a = 3;
    unsigned int b = 5;

    // 0011 & 0101 = 0001
    printf("%u\n", a & b);
    // 0011 | 0101 = 1000
    printf("%u\n", a | b);

    return 0;
}