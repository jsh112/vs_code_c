#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지

int dur(const char c) {
    return (c >= 'A' && c <= 'Z') ? (c - 'A') : (c - 'a');
}
char* my_strstr(char* s, char* t) {
    char* tmp = t;
    while (*tmp) {
        tmp++;
    }
    int len = tmp - t;

    while (*s) {
        if (dur(*s) == dur(*t)) {
            char* start_s = s;
            char* start_t = t;
            int match = 1;
            for (int i = 0; i < len; i++) {
                if (dur(*s) != dur(*t)) {
                    match = 0;
                    break;
                }
                s++;
                t++;
            }
            if (match) {
                return start_s;
            }
            t = start_t;
            s = start_s;
        }
        s++;
    }
    return NULL;
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