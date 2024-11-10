#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned int count_bit(unsigned char *cp) {
    // 이 위로 수정 금지
    const int n = 8;
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            if (*(cp + i) & (0x01 << j)) {
                cnt++;
            }
        }
    }
    return cnt;
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[]) {
    unsigned int A = 0, ans = 0;

    scanf("%X", &A);

    ans = count_bit((unsigned char *)&A);

    printf("%u", ans);

    return 0;
}
