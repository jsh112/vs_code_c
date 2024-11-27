#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
unsigned char make_parityBit_chunk(unsigned char *d) {
    unsigned char ans = 0;
    for (int i = 0; i < 8; i++) {
        int cnt = 0;
        for (int ii = 0; ii < 8; ii++) {
            int mask = 0x01 << ii;
            if (mask & *(d + i))
                cnt++;
        }
        if (cnt % 2 != 0) {
            ans |= (0x01 << (7 - i));
        }
    }
    return ans;
}
// 이 아래로 수정 금지

int main(int argc, char const *argv[]) {
    unsigned char data[8] = {0};
    for (size_t i = 0; i < 8; i++) {
        scanf("%hhX", data + i);
    }

    unsigned char ans = make_parityBit_chunk(data);

    printf("%X", ans);

    return 0;
}