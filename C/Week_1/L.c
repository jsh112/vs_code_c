#include <stdio.h>

int main()
{

    // c = A nand B
    // d = a or b
    // q = c and d

    unsigned int a, b;
    scanf("%u %u", &a, &b);

    unsigned int c = ~(a & b);
    unsigned int d = (a | b);
    unsigned int q = (c & d);

    printf("%u %u %u", c, d, q);

    return 0;
}