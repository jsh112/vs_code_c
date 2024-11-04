#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
void my_strchr(char* s, char c, char** p){
    while(*s){
        if(*s == c)
            break;
        s++;
    }
    if(*s)
        *p = s;
}
// 이 아래로 수정 금지

int main(int argc, char const *argv[])
{
    char S[101] = {0};
    char C;

    scanf("%[^\n]", S);
    scanf(" %c", &C);

    char *p = NULL;
    my_strchr(S, C, &p);

    if (p != NULL)
        printf("%ld", p - S);
    else
        printf("-1");

    return 0;
}
