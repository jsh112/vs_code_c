#include <stdio.h>

// int i;
// char a;
// char arr1[3];

int main()
{
    char a, b, c, d;
    int i = 1, j = 3, k = 4;
    char e, f, g;
    int l;
    char h;
    int m;
    char x[7];
    m = 0;
    char *basic = (char *)&a;
    printf("%d, %d, %d, %d\n", (char *)&a - basic, (char *)&b - basic, (char *)&c - basic, (char *)&d - basic);
    printf("%d, %d, %d\n", (char *)&i - basic, (char *)&j - basic, (char *)&k - basic);
    printf("%d, %d, %d\n", (char *)&e - basic, (char *)&f - basic, (char *)&g - basic);
    printf("%d\n", (char *)&l - basic);
    printf("%d, %d\n", (char *)&h - basic, (char *)&m - basic);
    printf("%d\n", (char *)&x - basic);
    printf("%d\n", (char *)&x[1] - basic);

    // unsigned char a = 5;
    // unsigned short j = 258;

    // a = j;
    // printf("%d", a);

    // char c = 5;
    // int x = 258;
    // char arr2[3];

    // x = c;

    return 0;
}
