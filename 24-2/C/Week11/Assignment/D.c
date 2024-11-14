#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void mat_product(unsigned int *A, unsigned int *B, unsigned int *C, unsigned int n, unsigned int k, unsigned int m) {
    // 이 위로 수정 금지
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x < k; x++) {
                C[100 * i + j] += A[100 * i + x] * B[100 * x + j];
            }
        }
    }
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[]) {
    unsigned int n, k, m;
    unsigned int A[100][100] = {0};
    unsigned int B[100][100] = {0};
    unsigned int C[100][100] = {0};

    scanf("%u %u %u", &n, &k, &m);
    for (size_t i = 0; i < n; i++)
        for (size_t ii = 0; ii < k; ii++)
            scanf("%u", A[i] + ii);
    for (size_t i = 0; i < k; i++)
        for (size_t ii = 0; ii < m; ii++)
            scanf("%u", B[i] + ii);

    mat_product((unsigned int *)A, (unsigned int *)B, (unsigned int *)C, n, k, m);

    for (size_t i = 0; i < n; i++)
        for (size_t ii = 0; ii < m; ii++)
            printf("%u%c", C[i][ii], ii == m - 1 ? '\n' : ' ');

    return 0;
}