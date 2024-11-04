#include <stdio.h>
#define SZ 8

int main() {
    unsigned int arr[SZ], ans[SZ] = {0};
    for (int i = 0; i < SZ; i++) {
        scanf("%X", &arr[i]);
    }
    int idx = 0;
    for (int j = 0; j < 4; j++) {
        for (; idx < 8; idx++) {
            int iidx = (idx < 4) ? 2 * j : (2 * j + 1);
            unsigned int mask = (arr[idx] >> (j * 8)) & 0xFF;
            ans[iidx] |= mask << (idx * 8);
        }
        idx = 0;
    }

    for (int i = 0; i < SZ; i++) {
        printf("%X ", ans[i]);
    }

    return 0;
}