#include <stdio.h>
#define SZ 8
int main() {
    unsigned int A[SZ], ans[SZ] = {0};
    for (int i = 0; i < SZ; i++) {
        scanf("%X", &A[i]);
    }

    /**
     * 0~3번째의 0번 바이트가 ans의 0번으로 집합
     * 4~7번째의 0번바이트가 ans의 1번으로 집합
     *
     *
     */

    for (int k = 0; k < 4; k++) {
        int j = 2 * k;
        int i = 0;
        for (; i < 4; i++) {
            ans[j] |= ((A[i] & (0xFF << (8 * k))) << (i * SZ)) >> (k * 8);
        }
        j++;
        for (; i < 8; i++) {
            ans[j] |= ((A[i] & (0xFF << (8 * k))) << (i * SZ)) >> (k * 8);
        }
    }

    for (int i = 0; i < SZ; i++) {
        printf("%X ", ans[i]);
    }

    return 0;
}