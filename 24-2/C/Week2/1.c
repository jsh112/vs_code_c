#include <stdio.h>

int main()
{

    unsigned char a[4] = {
        0,
    };
    unsigned char b;
    // scanf("%d", (int *)&a[0]);
    scanf("%c", (int *)&a[0]);

    // decimal 1193046 <-> hex 0x123456

    b = a[0] + a[2];
    printf("%d\n", b);
    return 0;
}