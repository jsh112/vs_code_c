#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
char *makeMessage(char *mes, char *name)
{
    char *tmp = mes;
    char *tmp_1 = "Hello ";
    char *tmp_2 = ", please come in.";
    while (*tmp_1)
    {
        *mes = *tmp_1;
        mes++;
        tmp_1++;
    }

    while (*name)
    {
        *mes = *name;
        mes++;
        name++;
    }

    while (*tmp_2)
    {
        *mes = *tmp_2;
        mes++;
        tmp_2++;
    }
    *mes = '\0';
    return tmp;
}
// 이 아래로 수정 금지

int main(int argc, char const *argv[])
{
    char name[100] = {0};
    char message[200] = {0};

    scanf("%[^\n]", name);

    makeMessage(message, name);

    printf("%s", message);

    return 0;
}