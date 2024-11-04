#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void mat_product(unsigned int *A, unsigned int *B, unsigned int *C) {
    // 이 위로 수정 금지
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                // C_ij = \sum(1~3) A_ik + B_kj
                C[2 * i + j] += (A[3 * i + k] * B[2 * k + j]);
            }
        }
    }
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[]) {
    unsigned int A[2][3] = {0};
    unsigned int B[3][2] = {0};
    unsigned int C[2][2] = {0};

    for (int i = 0; i < 6; i++)
        scanf("%u", *A + i);
    for (int i = 0; i < 6; i++)
        scanf("%u", *B + i);

    mat_product((unsigned int *)A, (unsigned int *)B, (unsigned int *)C);

    for (size_t i = 0; i < 2; i++)
        for (size_t ii = 0; ii < 2; ii++)
            printf("%u%c", C[i][ii], ii == 1 ? '\n' : ' ');

    return 0;
}