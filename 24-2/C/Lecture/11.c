#include <stdio.h>

int main()
{

    char a = 0, b[12] = "I am a boy";
    char *c = "I am a boy";
    int i[12] = {"I am a boy"};

    if (a == b)
        // x
        printf("1");
    if (c == b)
        // x
        printf("2");
    if (i == b)
        // x
        printf("3");
    if (c == b)
        // x
        printf("4");
    if (c == i)
        // x
        printf("5");
    if (b[0] == i[0])
        // x
        printf("6");
    if (c == i[0])
        // o
        printf("7");
    if (b[0] == c[0])
        // o
        printf("8");
    else
        // x
        printf("9");
    return 0;
}