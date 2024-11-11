#include <stdio.h>

int main() {
    char str1[100], str2[100];
    scanf("%[^/]", str1);
    getchar();
    scanf("%s", str2);

    int len1 = 0, len2 = 0;
    char *p1 = str1, *p2 = str2;
    while (*p1) {
        p1++;
    }
    len1 = p1 - str1;

    while (*p2) {
        p2++;
    }
    len2 = p2 - str2;

    int len_min = (len1 < len2) ? len1 : len2;
    int len_max = (len1 > len2) ? len1 : len2;

    for (int i = 0; i < len_min; i++) {
        for (int j = 0; j < len_max; j++) {
            if (len_min == len1) {
                if (str1[i] == str2[j]) {
                    str1[i] = '-';
                    str2[j] = '-';
                }
            }
            if (len_min == len2 && len1 != len2) {
                if (str1[j] == str2[i]) {
                    str1[j] = '-';
                    str2[i] = '-';
                }
            }
        }
    }

    for (int i = 0; i < len1; i++) {
        if (str1[i] != '-') {
            printf("%c", str1[i]);
        }
    }
    printf("/");
    for (int j = 0; j < len2; j++) {
        if (str2[j] != '-') {
            printf("%c", str2[j]);
        }
    }

    return 0;
}