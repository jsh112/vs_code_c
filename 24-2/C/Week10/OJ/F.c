#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int N;
    scanf("%u", &N);
    unsigned int* arr;
    arr = malloc(sizeof(int) * N);

    unsigned int num;
    for (int i = 0; i < N; i++) {
        scanf("%u", &arr[i]);
    }

    for (int i = N; i > 0; i--) {
        printf("%u ", arr[i - 1]);
    }

    free(arr);

    return 0;
}