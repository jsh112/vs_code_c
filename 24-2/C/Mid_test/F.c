#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char *my_strcat(char *destination, char *source)
{
    // 이 위로 수정 금지
    char *tmp = destination;
    while (*tmp)
    {
        tmp++;
    }
    while (*source)
    {
        *tmp = *source;
        tmp++;
        source++;
    }
    *tmp = '\0';
    // 이 아래로 수정 금지
    return destination;
}

int main(int argc, char const *argv[])
{
    char S1[201] = {
        0,
    };
    char S2[201] = {
        0,
    };

    scanf("%[^\n]\n", S1);
    scanf("%[^\n]", S2);

    char *p = my_strcat(S1, S2);
    printf("%s", p);
}