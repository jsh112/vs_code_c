#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count_bit(unsigned char *A, int N, int *B) {
    // 이 위로 수정 금지
    int ii = 0, i = 0;
    for (; i < 32; i += N) {
        int cnt = 0;
        for (int j = i; j < i + N && j < 32; j++) {
            int idx = j / 8;
            int iidx = j % 8;
            if (0x01 & (*(A + (3 - idx)) >> (7 - iidx))) {
                cnt++;
            }
        }
        *(B + ii) = cnt;
        ii++;
    }
    *(B + ii) = -1;
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[]) {
    unsigned int A = 0;
    int N = 0;
    int B[33] = {0};

    scanf("%X %d", &A, &N);

    count_bit((unsigned char *)&A, N, B);

    for (size_t i = 0; i < 33 && B[i] != -1; i++) {
        printf("%d ", B[i]);
    }

    return 0;
}
