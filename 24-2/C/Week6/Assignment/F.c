#include <stdio.h>

int main()
{

    unsigned int a, n;
    scanf("%d %d", &a, &n);

    printf("%d", ((a & 0xF0) << n) & 0xF0 | ((a & 0xF) >> n & 0xF));

    return 0;
}