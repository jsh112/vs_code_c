#include <stdio.h>

int main()
{

    int i;
    scanf("%d", &i);

    printf("%X", 0x1000 + (i * sizeof(char) * 30));

    return 0;
}