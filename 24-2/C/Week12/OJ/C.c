#include <stdio.h>

int main() {
    unsigned int n;
    scanf("%hhu", &n);

    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int mask = 0x01 << i;
        if (mask & n) {
            cnt++;
        }
    }

    if (cnt % 2 == 0) {
        printf("%X", n | (0x01 << 7));
    } else {
        printf("%X", n & ~(0x01 << 7));
    }

    return 0;
}