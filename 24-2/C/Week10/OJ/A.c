#include <stdio.h>

int main() {
    unsigned int a;
    scanf("%u", &a);

    int cnt = 0;
    int arr[8] = {0};
    for (int i = 0; i < 7; i++) {
        if ((a & (0x01 << i)) != (0x01 << i))
            arr[i] = 1;
        else
            cnt++;
    }

    if (cnt % 2 != 0) {
        a |= (0x01 << 7);
    }
    printf("%X", a);

    return 0;
}