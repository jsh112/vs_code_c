#include <stdio.h>

int main() {
    unsigned int a;
    scanf("%u", &a);

    int cnt = 0;
    int arr[8] = {0};
    for (int i = 0; i < 7; i++) {
        unsigned int num = a & (0x01 << i);
        if (num)
            cnt++;
    }

    if (cnt % 2 != 0) {
        a |= (0x01 << 7);
    }
    printf("%X", a);

    return 0;
}