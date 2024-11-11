#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void rgb2gray(unsigned char *gray, unsigned char *rgb, unsigned int n, unsigned int m) {
    // 이 위로 수정 금지
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int k = 0; k < 3; k++) {
                sum += rgb[(300 * i) + 3 * j + k];
            }
            gray[i * 100 + j] = (char)(sum / 3);
        }
    }
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[]) {
    unsigned char rgb[100][100][3] = {0};
    unsigned char gray[100][100] = {0};
    unsigned int N, M;
    scanf("%u %u", &N, &M);
    for (size_t i = 0; i < N; i++) {
        for (size_t ii = 0; ii < M; ii++) {
            scanf("%hhu %hhu %hhu", rgb[i][ii], rgb[i][ii] + 1, rgb[i][ii] + 2);
        }
    }

    rgb2gray((unsigned char *)gray, (unsigned char *)rgb, N, M);

    for (size_t i = 0; i < N; i++) {
        for (size_t ii = 0; ii < M; ii++) {
            printf("%u%c", gray[i][ii], ii == M - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
