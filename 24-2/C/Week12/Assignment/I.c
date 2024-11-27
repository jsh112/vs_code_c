#include <stdio.h>

int main() {
    const int sz = 8;
    int m[sz][sz], N;

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    scanf("%d", &N);

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            m[i][j] = (i < N || j < N || i >= sz - N || j >= sz - N) ? 0 : m[i][j];
        }
    }

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}