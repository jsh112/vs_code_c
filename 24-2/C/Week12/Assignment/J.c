#include <stdio.h>

const int sz = 8;

void zeropaddingbit(unsigned int m[], int N) {
    unsigned int mask = (0xFF >> N) & (0xFF << N);

    for (int i = 0; i < sz; i++) {
        m[i] &= (i < N || i >= sz - N) ? 0 : mask;
    }

    for (int i = 0; i < sz; i++) {
        printf("%X ", m[i]);
    }
}

int main() {
    unsigned int mat[sz];
    int N;

    for (int i = 0; i < sz; i++) {
        scanf("%X", &mat[i]);
    }
    scanf("%d", &N);
    zeropaddingbit(mat, N);
    return 0;
}