#include <stdio.h>

int main() {
    int arr[4], ans[4] = {0};
    for (int i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 8; i++) {
        int ii = i * 4;
        int idx = i / 8;
        int iidx = ii % 8;
        for (int j = 0; j < 4; j++) {
            int mask = (arr[j] >> (7 - i)) & 0x01;
            if (mask) {
                ans[idx] |= (0x01 << (7 - iidx));
            }
            iidx++;
        }
    }

    for(int i=0;i<4;i++){
        printf("%d ", ans[i]);
    }

    return 0;
}