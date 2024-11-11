#include <stdio.h>

int main() {
    char str[110];
    gets(str);

    char *p = str;
    int len;
    while (*p) {
        p++;
    }
    len = p - str;

    for (int i = 1; i < len; i++) {
        char key = str[i];
        int j = i - 1;
        while (j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = key;
    }

    printf("%s", str);

    return 0;
}