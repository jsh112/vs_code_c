#include <stdio.h>

void my_strcpy(char* dest, const char* src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = 0;
}

int my_strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

void string_sort(char str[][110], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }

    for (int i = 1; i < n; i++) {
        char key[110];
        my_strcpy(key, str[i]);
        int j = i - 1;
        while (j >= 0 && (my_strcmp(str[j], key) > 0)) {
            my_strcpy(str[j + 1], str[j]);
            j--;
        }
        my_strcpy(str[j + 1], key);
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char str[n][110];

    string_sort(str, n);

    return 0;
}
