#include <stdio.h>

int main()
{

    int i;
    scanf("%d", &i);
    int k = 0x1000;
    printf("%X", k + sizeof(int) * i);
    return 0;
}