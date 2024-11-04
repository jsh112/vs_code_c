#include <stdio.h>

int main() {
    /**
     * 5바이트의 비트시프트
     * 0바이트 1바이트 ... 4바이트
     * ans
     */

    int a[5], ans[5] = {0};
    for (int i = 0; i < 5; i++) {
        scanf("%X", &a[i]);
    }

    int n;
    scanf("%d", &n);

    if (n < 0) {
        // 음수 -> 오른쪽 쉬프트

        // 양수로 만듦
        n = -n;
        for (int i = 0; i < 5 * 8; i++) {
            int t = i + n;
            // 바이트의 위치
            int j = i / 8;
            int jj = i % 8;
            // 1000 0000
            int mask = a[j] & (0x80 >> jj);

            if (t < 40) {
                int idx = t / 8;
                int iidx = t % 8;
                // if(mask) -> mask가 0이 아닌 모든 수
                // mask -> 0b 1000 0000
                if (mask) {
                    // ans[idx] = ans[idx] | (0x80 >> iidx);
                    ans[idx] |= (0x80 >> iidx);
                }
            }
        }
    } else {
        // 양수 -> 왼쪽 쉬프트
        n = -n;
        for (int i = 0; i < 5 * 8; i++) {
            int t = i + n;
            int j = i / 8;
            int jj = i % 8;
            int mask = a[j] & (0x80 >> jj);

            if (t >= 0) {
                int idx = t / 8;
                int iidx = t % 8;
                if (mask) {
                    ans[idx] |= (0x80 >> iidx);
                }
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%X ", ans[i]);
    }

    return 0;
}