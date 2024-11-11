#include <stdio.h>

int main() {
    unsigned int arr[3], ans[3] = {0};

    for (int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 24; i += 3) {
        for (int ii = i; ii < i + 3 && ii < 24; ii++) {
            
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}