#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
void set_parityBit_arr(unsigned char* d) {
    for (int i = 0; i < 4; i++) {
        int cnt = 0;
        for (int ii = 0; ii < 8; ii++) {
            unsigned char mask = 1 << ii;
            if (mask & d[i])
                cnt++;
        }
        if (cnt % 2 == 0) {
            d[i] |= (unsigned char)(1 << 7);
        }
    }
}
// 이 아래로 수정 금지

int main(int argc, char const* argv[]) {
    unsigned char data[4] = {0};

    scanf("%hhX %hhX %hhX %hhX", data, data + 1, data + 2, data + 3);

    set_parityBit_arr(data);

    printf("%X %X %X %X", data[0], data[1], data[2], data[3]);

    return 0;
}