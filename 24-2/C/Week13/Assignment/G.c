#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
void set_parityBit_arr(unsigned char* d) {
    for (int i = 0; i < 4; i++) {
        int cnt = 0;
        for (int j = 0; j < 8; j++) {
            int mask = 1 << j;
            if (d[i] & mask)
                cnt++;
        }
        if (cnt % 2 == 0) {
            d[i] ^= (1 << 7);
        }
    }
}
// 이 아래로 수정 금지

int main(int argc, char const* argv[]) {
    unsigned char data[4] = {0};

    scanf("%hhu %hhu %hhu %hhu", data, data + 1, data + 2, data + 3);

    set_parityBit_arr(data);

    printf("%u %u %u %u", data[0], data[1], data[2], data[3]);

    return 0;
}