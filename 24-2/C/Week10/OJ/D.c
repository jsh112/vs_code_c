#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
unsigned int dot_product(unsigned int A[], unsigned int B[], int N) {
    unsigned int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (A[i] * B[i]);
    }
    return sum;
}

// 이 아래로 수정 금지

int main(int argc, char const *argv[]) {
    unsigned int N = 0;
    unsigned int A[100] = {0};
    unsigned int B[100] = {0};

    scanf("%u", &N);
    for (int i = 0; i < N; i++)
        scanf("%u", A + i);
    for (int i = 0; i < N; i++)
        scanf("%u", B + i);

    unsigned int res = dot_product(A, B, N);

    printf("%u", res);

    return 0;
}
