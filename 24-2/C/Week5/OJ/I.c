#include <stdio.h>

int main()
{

    char t[20];
    // gets(t);

    // if (t[0] == 'c')
    // {
    //     printf("%X", 0x1000 + sizeof(char) * ((t[5] - '0') * 30 + (t[7] - '0') * 5 + (t[9] - '0')));
    // }
    // else if (t[0] == 's')
    // {
    //     printf("%X", 0x1000 + sizeof(short) * ((t[6] - '0') * 30 + (t[8] - '0') * 5 + (t[10] - '0')));
    // }
    // else
    // {
    //     printf("%X", 0x1000 + sizeof(int) * ((t[4] - '0') * 30 + (t[6] - '0') * 5 + (t[8] - '0')));
    // }

    int a, b, c;
    scanf("%s", t);
    scanf("%d %d %d", &a, &b, &c);

    return 0;
}