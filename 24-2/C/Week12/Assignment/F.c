#include <stdio.h>

void selection_sort(unsigned int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int ii = i + 1; ii < n; ii++) {
            if (arr[ii] < arr[min_idx]) {
                min_idx = ii;
            }
        }
        unsigned int tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
        for (int j = 0; j < n; j++) {
            printf("%u ", arr[j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    unsigned int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%u", &arr[i]);
    }

    selection_sort(arr, n);

    return 0;
}