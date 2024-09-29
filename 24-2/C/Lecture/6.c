#include <stdio.h>

int main()
{
    int i[3][4] = {};
    printf("%d\n", (char *)(i + 1) - (char *)&i);

    return 0;
}