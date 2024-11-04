#include <stdio.h>

int main() {
    unsigned int N, ans = 0;
    scanf("%X", &N);

    // 제일 낮은 주소부터
    // 78 56 34 12

    // p, p+1, p+2, p+3

    // 12 34 56 78
    unsigned char* p = (unsigned char*)&N;
    for (int i = 0; i < 4; i++) {
        ans |= (*(p + 3 - i) << (8 * i));
    }
    printf("%X", ans);

    return 0;
}