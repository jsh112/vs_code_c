#include <stdio.h>

int main() {
    int sz;
    scanf("%d", &sz);
    unsigned int arr[sz];
    for (int i = 0; i < sz; i++) {
        scanf("%u", &arr[i]);
    }

    for (int i = 1; i < sz; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        for (int ii = 0; ii < sz; ii++) {
            printf("%d ", arr[ii]);
        }
        printf("\n");
    }

    return 0;
}