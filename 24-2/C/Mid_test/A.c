#include <stdio.h>

int main()
{

    char str[100];
    scanf("%s", str);

    int i = 0;
    while (str[i] != '\0')
    {
        int num = (str[i] - '0');
        switch (num)
        {
        case 1:
            printf("!");
            break;
        case 2:
            printf("@");
            break;
        case 3:
            printf("#");
            break;
        case 4:
            printf("$");
            break;
        case 5:
            printf("%%");
            break;
        case 6:
            printf("^");
            break;
        case 7:
            printf("&");
            break;
        case 8:
            printf("*");
            break;
        case 9:
            printf("(");
            break;
        case 0:
            printf(")");
            break;
        default:
            break;
        }
        i++;
    }

    return 0;
}