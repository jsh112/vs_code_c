#include <stdio.h>

int main() {
    const int num = 60;
    unsigned int arr[num];
    for (int i = 0; i < num; i++) {
        scanf("%u", arr + i);
    }

    for (int i = 1; i < 60; i++) {
        int j = i - 1;
        unsigned int key = arr[i];

        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j] = key;

    }

    for (int i = 0; i < num; i++) {
        printf("%u ", arr[i]);
    }

    return 0;
}