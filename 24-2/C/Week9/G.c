#include <stdio.h>
const int sz = 4;

int main() {
    unsigned int arr[sz];
    int n;

    for (int i = 0; i < sz; i++) {
        scanf("%X", &arr[i]);
    }
    scanf("%d", &n);

    int bits = sz * 32;

    for (int i = 0; i < bits; i += n) {
        int cnt = 0;
        for (int ii = i; ii < i + n && ii < bits; ii++) {
            int idx = ii >> 5;
            int iidx = ii % 31;
            if (arr[idx] & (0x01 << (31 - iidx)))
                cnt++;
        }
        printf("%d ", cnt);
    }

    return 0;
}
