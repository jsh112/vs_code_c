#include <stdio.h>

int main() {
    int h, p;
    scanf("%X %d", &h, &p);

    // 3 기준
    // 0,1,2 // 4,5,6

    for (int i = 0; i < 20; i++) {
        if ((i < p && i >= p - 3) || (i <= p + 3 && i > p)) {
            h &= ~(0x01 << i);
        }
    }
    printf("%X", h);

    return 0;
}