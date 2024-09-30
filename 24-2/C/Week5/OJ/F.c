#include <stdio.h>

int main()
{

    int p;
    scanf("%x", &p);
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%X", p + sizeof(short) * (b + 5 * a));

    // int a[2][3];
    // a[1] + 1
    // a + 1 == &a[0] + 1 == &a[1] == 0x1000 + sizeof(int) * 3
    // a[1] == &a[1][0]
    // &a[1][0] + 1 = &a[1]

    return 0;
}