#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char *my_strstr(char *str1, char *str2)
{
    // 이 위로 수정 금지
    char *tmp = str1;
    while (*tmp)
    {
        char *tmp1 = tmp;
        char *tmp2 = str2;

        while (*tmp1 && *tmp2 && *tmp1 == *tmp2)
        {
            tmp1++;
            tmp2++;
        }
        if (!*tmp2)
        {
            return tmp;
        }
        tmp++;
    }
    return NULL;
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[])
{
    char S1[104] = {0};
    char S2[104] = {0};

    fgets(S1, 100, stdin);
    fgets(S2, 100, stdin);

    char *p = my_strstr(S1, S2);

    if (p != NULL)
        printf("%ld", p - S1);
    else
        printf("-1");

    return 0;
}