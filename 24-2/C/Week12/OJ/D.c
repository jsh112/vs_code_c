#include <stdio.h>

int main() {
    unsigned int n, ans = 0;
    scanf("%d", &n);

    int idx = 0;
    for (int i = 0; i < 32; i++) {
        int mask = 0x01 << i;
        if (n & mask) {
            ans |= (0x01 << idx);
            idx++;
        }
    }
    printf("%d", ans);

    return 0;
}