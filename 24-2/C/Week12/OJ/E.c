#include <stdio.h>

int main() {
    const int n = 8;
    int arr[n], ans[n];
    for (int i = 0; i < n; i++) {
        scanf("%X", &arr[i]);
        if (i < 4) {
            ans[i] = arr[i];
        } else {
            ans[i] = 0;
        }
    }

    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            int mask = 0x01 << j;
            if(arr[i] & mask){
                ans[7 - i] |= (0x01 << (7 - j));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%X ", ans[i]);
    }

    return 0;
}