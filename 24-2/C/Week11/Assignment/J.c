#include <stdio.h>

int main() {
    unsigned char n, ans = 0;
    scanf("%hhu", &n);

    int idx = 0;
    for (int i = 0; i < 8; i++) {
        int mask = 0x01 << i;
        if (mask & n) {
            ans |= (0x01 << idx);
            idx++;
        }
    }
    printf("%d", ans);

    return 0;
}