#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
void string_ptr_swap(char **p1, char **p2) {
    char *p;
    p = *p1;
    *p1 = *p2;
    *p2 = p;
}

void real_string_swap(char *p2, char *p3) {
    while (*p2 || *p3) {
        char c = *p2;
        *p2 = *p3;
        *p3 = c;
        p2++;
        p3++;
    }
}
// 이 아래로 수정 금지

int main(int argc, char const *argv[]) {
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