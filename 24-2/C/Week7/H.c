#include <stdio.h>

char *my_strcpy(char *destination, char *source)
{
    // 이 위로 수정 금지
    char *tmp = destination;
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
    char S[101] = {0};
    char target[101] = {0};

    scanf("%[^\n]", S);
    char *result = my_strcpy(target, S);
    printf("%s", result);
}