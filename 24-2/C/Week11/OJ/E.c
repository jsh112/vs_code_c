#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지

int dur(char c) {
    return (c >= 'A' && c <= 'Z') ? (c - 'A') : (c - 'a');
}

char* my_strstr(char* s, char* t) {
    char* ttmp = t;

    char* tmp = s;
    while (*s) {
        if (dur(*s) == dur(*t)) {
            char* cur_s = s;
            char* cur_t = t;

            while (*s && *cur_t && (dur(*s) == dur(*cur_t))) {
                s++;
                cur_t++;
            }

            if (!*cur_t) {
                return cur_s;
            } else {
                return NULL;
            }
        }
        s++;
    }
}
// 이 아래로 수정 금지

int main(int argc, char const* argv[]) {
    char S[100] = {0};
    char T[100] = {0};
    scanf("%[^\n]\n", S);
    scanf("%[^\n]", T);

    char* p = my_strstr(S, T);

    printf("%s", p != NULL ? p : S);

    return 0;
}