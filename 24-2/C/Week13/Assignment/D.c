#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지

int my_strcmp(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        if (*s1 > *s2)
            return 1;
        else if (*s1 < *s2)
            return -1;
        else {
            s1++;
            s2++;
        }
    }
    if (*s1)
        return 1;
    else if (*s2) {
        return -1;
    }
    return 0;
}

void my_strcpy(char* s1, char* s2) {
    while (*s2) {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = 0;
}

void sort_str(char str[][100], unsigned int n) {
    char key[100];
    for (size_t i = 1; i < n; i++) {
        my_strcpy(key, str[i]);
        size_t j = i;
        while (j > 0 && my_strcmp(str[j - 1], key) > 0) {
            my_strcpy(str[j], str[j - 1]);
            j--;
        }
        my_strcpy(str[j], key);
    }
}
// 이 아래로 수정 금지

int main(int argc, char const* argv[]) {
    unsigned int N;
    char data[100][100] = {0};
    scanf("%u", &N);
    for (size_t i = 0; i < N; i++)
        scanf("%s", data[i]);

    sort_str(data, N);

    for (size_t i = 0; i < N; i++)
        printf("%s\n", data[i]);

    return 0;
}
