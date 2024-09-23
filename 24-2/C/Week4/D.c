#include <stdio.h>

int main()
{

    int i;
    scanf("%x", &i);
    int k = 0x1000;
    int n1 = (i - k) / 20;
    i -= n1 * 20;
    int n2 = (i - k) / 4;
    printf("%d %d", n1, n2);
    return 0;
}