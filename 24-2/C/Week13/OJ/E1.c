#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    unsigned int **data = NULL;
    unsigned int N, M;
    scanf("%u %u", &N, &M);

    // 이 사이에 코드 작성 1
    *data = (unsigned int **)malloc(sizeof(unsigned int *) * N);
    for (int i = 0; i < N; i++) {
        *(data + i) = (unsigned int *)malloc(sizeof(unsigned int) * M);
    }
    // 이 사이에 코드 작성 1

    for (size_t i = 0; i < N; i++) {
        for (size_t ii = 0; ii < M; ii++) {
            scanf("%u", &data[i][ii]);
        }
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t ii = 0; ii < M; ii++) {
            printf("%u%c", data[i][ii], ii == M - 1 ? '\n' : ' ');
        }
    }

    // 이 사이에 코드 작성 2
    for (int i = 0; i < M; i++) {
        free(*data + i);
        for (int j = 0; j < N; j++) {
            free(data + j);
        }
    }
    // 이 사이에 코드 작성 2

    return 0;
}