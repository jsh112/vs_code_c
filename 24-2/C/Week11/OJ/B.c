#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
void string_ptr_swap(char** s1, char** s2){
    char *tmp;
    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

void real_string_swap(char* s1, char* s2){
    while(*s1 || *s2){
        char c = *s1;
        *s1 = *s2;
        *s2 = c;
        s1++;
        s2++;
    }
    if(*s1){
        *s1 = 0;
    }
    if(*s2){
        *s2 = 0;
    }
}
// 이 아래로 수정 금지

int main(int argc, char const *argv[])
{
    char S1[100] = {0};
    char S2[100] = {0};
    char S3[100] = {0};

    scanf("%[^\n]\n%[^\n]\n%[^\n]", S1, S2, S3);

    char *p1 = S1;
    char *p2 = S2;
    char *p3 = S3;

    string_ptr_swap(&p1, &p2);
    real_string_swap(p2, p3);

    printf("%s\n%s\n%s\n", S1, S2, S3);
    printf("%s\n%s\n%s\n", p1, p2, p3);

    return 0;
}
