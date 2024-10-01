#include <stdio.h>

int my_strcmp(const char *s1, const char *s2)
{
    // is same to (*s1 != '\0 && *s2 != '\0')
    if (*s1 && *s2)
    {
        if (*s1 != *s2)
        {
            return 0;
        }
        s1++;
        s2++;
    }
    return 1;
}

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

    int a, b, c, addr = 0x1000;
    scanf("%s", t);
    scanf("%d %d %d", &a, &b, &c);

    if (my_strcmp("char", t))
    {
        printf("%X", addr + sizeof(char) * ((a * 30) + (b * 5) + c));
    }
    else if (my_strcmp("short", t))
    {
        printf("%X", addr + sizeof(short) * ((a * 30) + (b * 5) + c));
    }
    else
    {
        printf("%X", addr + sizeof(int) * ((a * 30) + (b * 5) + c));
    }

    return 0;
}