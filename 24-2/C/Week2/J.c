#include <stdio.h>

# dfsdf
int main()
{
    unsigned int n;
    int num, cnt = 0;
    char str[10];
    gets(str);
    while (str[cnt] != '\0')
    {
        num = str[cnt] - '0';
        cnt++;

        switch (num)
        {
        case 0:
            printf("p");
            break;
        case 1:
            printf("q");
            break;
        case 2:
            printf("w");
            break;
        case 3:
            printf("e");
            break;
        case 4:
            printf("r");
            break;
        case 5:
            printf("t");
            break;
        case 6:
            printf("y");
            break;
        case 7:
            printf("u");
            break;
        case 8:
            printf("i");
            break;
        case 9:
            printf("o");
            break;
        }
    }
    return 0;
}