#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
int moving_into_apartment(int state[][3], int f, int h) {
    if (state[f - 1][h - 1] == 0) {
        state[f - 1][h - 1] = 5;
        return 0;
    } else {
        return 1;
    }
}
// 이 아래로 수정 금지

int main(int argc, char const *argv[]) {
    int state[50][3] = {0};
    int N = 0;
    int f[100] = {0};
    int h[100] = {0};

    scanf("%d", &N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", f + i, h + i);
    }

    for (size_t i = 0; i < N; i++) {
        printf("%d\n", moving_into_apartment(state, f[i], h[i]));
    }

    return 0;
}