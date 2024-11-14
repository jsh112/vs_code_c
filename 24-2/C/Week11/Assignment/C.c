#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int len1 = 0, len2 = 0;
    scanf("%[^/]", str1);
    getchar();
    scanf("%s", str2);

    while (str1[len1]) len1++;
    while (str2[len2]) len2++;

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                str1[i] = '-';
                str2[j] = '-';
                break;
            }
        }
    }

    for (int i = 0; i < len1; i++) if (str1[i] != '-') putchar(str1[i]);
    printf("/");
    for (int j = 0; j < len2; j++) if (str2[j] != '-') putchar(str2[j]);

    return 0;
}
