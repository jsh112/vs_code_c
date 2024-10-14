#include <stdio.h>

int main()
{

    char s[100];
    int a, b, i;
    scanf("%s arr[%d][%d]", s, &a, &b);
    getchar();
    scanf("%d", &i);

    if (s[0] == 'i')
    {
        printf("%X", 0x1000 + sizeof(int) * b * i);
    }
    else if (s[0] == 'c')
    {
        printf("%X", 0x1000 + sizeof(char) * b * i);
    }
    else
    {
        printf("%X", 0x1000 + sizeof(short) * b * i);
    }

    return 0;
}