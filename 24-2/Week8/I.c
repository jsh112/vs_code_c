#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int s[N], idx[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &idx[i]);
    }


    // 3
    // 2 3 4 배열의 크기
    // 0 1 3 -> 인덱스
    // 0 * (3*4) + 1 * (4) + 3 
    int factor = 1;
    unsigned int sum = 0;
    for (int i = 0; i < N; i++) {
        // (sum += )
        // idx[i] * 1;
        // idx[i] * 1 * s[i-1];
        // idx[i] * 1 * s[i-1] * s[i-2]
        if (i > 0)
            factor *= s[N - i];
        sum += idx[N - 1 - i] * factor;
    }
    // abcde
    // 01234
    printf("%X", sum * sizeof(short));
    return 0;   
}