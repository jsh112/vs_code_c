#include <stdio.h>

int main()
{

    int i;
    scanf("%x", &i);
    int k = 0x1000;
    printf("%d", (i - k) / sizeof(int));
    return 0;
}