#include <stdio.h>

int main() {
    int h1, m1, s1;
    int h2, m2, s2;

    scanf("%d:%d:%d", &h1, &m1, &s1);
    scanf("%d:%d:%d", &h2, &m2, &s2);

    int s = s1 + s2;
    int m = m1 + m2;
    int h = h1 + h2;

    if (s >= 60) {
        m++;
        s -= 60;
    }

    if (m >= 60) {
        h++;
        m -= 60;
    }

    if (h >= 24)
        h -= 24;

    printf("%02d:%02d:%02d", h, m, s);

    return 0;
}