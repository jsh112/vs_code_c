#include <stdio.h>

int main() {
    unsigned int T;
    int n, a;
    scanf("%X", &T);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        T &= ~(0x01 << (31 - a));
    }
    printf("%X", T);

    return 0;
}