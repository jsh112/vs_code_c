#include <stdio.h>

int main() {
    int h, p;
    scanf("%X %d", &h, &p);

    for (int i = 0; i < 20; i++) {
        if ((i >= p - 3 && i <= p + 3) && i != p) {
            h &= ~(0x01 << i);
        }
    }
    printf("%X", h);

    return 0;
}