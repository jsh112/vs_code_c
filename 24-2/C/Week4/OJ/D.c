#include <stdio.h>

int main()
{

    int A;
    scanf("%x", &A);

    int a1 = (A - 0x1000) / 20;
    A -= a1 * 20;
    int a2 = (A - 0x1000) / 4;
    printf("%d %d\n", a1, a2);

    return 0;
}