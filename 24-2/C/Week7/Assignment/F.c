#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap_str(char *str1, char *str2)
{
    // 이 위로 수정 금지
    char *tmp1 = str1;
    char *tmp2 = str2;
    char c;

    int len1 = 0, len2 = 0, len;
    while (*(str1 + len1))
        len1++;
    while (*(str1 + len2))
        len2++;
    len = (len1 < len2) ? len1 : len2;
    for (int i = 0; i < len; i++)
    {
        char c = *tmp1;
        *tmp1 = *tmp2;
        *tmp2 = c;
        tmp1++;
        tmp2++;
    }

    if (len == len1)
    {
        char *tmp = tmp2;
        while (*tmp2)
        {
            *tmp1 = *tmp2;
            *tmp1++;
            *tmp2++;
        }
        *tmp = '\0';
        *tmp1 = '\0';
    }
    else
    {
        char *tmp = tmp1;
        while (*tmp1)
        {
            *tmp2 = *tmp1;
            *tmp1++;
            *tmp2++;
        }
        *tmp = '\0';
        *tmp2 = '\0';
    }

    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[])
{
    char str1[104] = {0};
    char str2[104] = {0};
    scanf("%[^\n]\n", str1);
    scanf("%[^\n]", str2);

    swap_str(str1, str2);

    printf("%s\n%s", str1, str2);
    return 0;
}