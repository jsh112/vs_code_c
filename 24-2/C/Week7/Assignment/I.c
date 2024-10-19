#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int my_atoi(char *str)
{
    // 이 위로 수정 금지
    int sum = 0;
    while (*str)
    {
        sum = sum * 10 + (*str - '0');
        str++;
    }
    return sum;
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[])
{
    char S[101] = {0};

    scanf("%s", S);

    printf("%d", my_atoi(S));

    return 0;
}