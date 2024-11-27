#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define READ_BIT(X, N) (((X) >> (N)) & 1)

// 이 위로 수정 금지
void Amen(int x, int y, unsigned char* b) {
    // 3, 3
    // j == 3 -> 1
    // i == 3 -> 0xFF
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == x) {
                b[i] = 0xFF;
            }
            if (j == y) {
                b[i] |= 0x01 << (7 - j);
            }
        }
    }
}
// 이 아래로 수정 금지

int main(int argc, char const* argv[]) {
    int x, y;
    unsigned char board[8] = {0};

    scanf("%d %d", &x, &y);

    Amen(x, y, board);

    for (size_t i = 0; i < 8; i++) {
        for (size_t ii = 0; ii < 8; ii++) {
            if (READ_BIT(board[i], 7 - ii))
                printf("+");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
