#include <stdio.h>

int main() {
    unsigned int A;
    scanf("%X", &A);

    int mask = 0x01 << 23;

    A &= 0xFFF000;
    for (int i = 0; i < 12; i++) {
        int a = ((mask & A) >> (23 - i));
        A |= (a << i);
        mask >>= 1;
    }

    for (int i = 5; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            printf("%d", (A >> (4 * i + j)) & 0x01);
        }
        printf(" ");
    }

    return 0;
}