#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    unsigned int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%u", &a[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                unsigned int tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
        for (int ii = 0; ii < n; ii++) {
            printf("%u ", a[ii]);
        }
        printf("\n");
    }

    return 0;
}