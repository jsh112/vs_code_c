#include <stdio.h>

int main() {
    unsigned int A, ans1 = 0;
    scanf("%X", &A);

    ans1 |= (A & (0xFFFF << 16));
    for (int i = 0; i < 16; i++) {
        if (A & (0x01 << (31 - i)))
            ans1 |= (0x01 << i);
    }
    printf("%X\n%d", ans1, ans1);

    return 0;
}