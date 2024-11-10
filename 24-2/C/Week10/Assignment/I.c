#include <stdio.h>

int duration(char c) {
    return (c >= 'a' && c <= 'z') ? (c - 'a') : (c - 'A');
}

void my_strstr(const char* s, const char* t) {
    const char* start = s;
    while (*s) {
        // 시작
        if (duration(*s) == duration(*t)) {
            const char* tmp_s = s;
            const char* tmp_t = t;

            while (*tmp_s && *tmp_t && (duration(*tmp_s) == duration(*tmp_t))) {
                tmp_s++;
                tmp_t++;
            }

            if (!*tmp_t) {
                printf("%s\n", s);
                return;
            }
        }
        s++;
    }
    printf("%s", start);
}

int main() {
    char s[110], t[110];
    gets(s);
    gets(t);

    my_strstr(s, t);
    return 0;
}
