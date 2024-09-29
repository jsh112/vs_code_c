#include <stdio.h>

int main()
{

    // int j = 258;
    // char i = *((char *)((char *)&j + 1));
    // printf("%d\n", (char *)&j);
    // printf("%d\n", ((char *)&j + 1) - (char *)&j);

    // printf("%d\n", ((char *)((char *)&j + 1)) - (char *)&j);

    // int a[7] = "12345";
    size_t a = (char *)"12345";

    return 0;
}