#include <stdio.h>

int main() {
    unsigned int A, ans1 = 0;
    scanf("%X", &A);

    ans1 = (A & (0xFFFF << 16));
    for (int i = 0; i < 16; i++) {
        unsigned int num = ((A >> (31 - i)) & 0x01);
        ans1 |= (num << i);
    }
    printf("%X\n%d", ans1, ans1);

    return 0;
}