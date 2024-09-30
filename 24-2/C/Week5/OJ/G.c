#include <stdio.h>

int main()
{

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%X", 0x1000 + sizeof(char) * (c + 5 * b + a * 30));

    return 0;
}