#include <stdio.h>

int main()
{

    char s[100], s_int[100], s_char[100];
    gets(s);
    int len = 0, len1 = 0, len2 = 0;
    while (s[len] != '\0')
    {
        if (s[len] - '0' > 9)
        {
            s_char[len2++] = s[len];
        }
        else
        {
            s_int[len1++] = s[len];
        }
        len++;
    }
    for (int j = 0; j < len2; j++)
    {
        printf("%c", s_char[j]);
    }
    printf("\n");
    for (int i = 0; i < len1; i++)
    {
        printf("%c", s_int[i]);
    }

    return 0;
}