#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define READ_BIT(X, N) (((X) >> (N)) & 1)

void wakanda_forever(int x, int y, unsigned char *board) {
    // 이 위로 수정 금지
    for (int i = 0; i < 8; i++) {
        if ((x - i >= 0) && (y - i) >= 0) {
            board[x - i] |= (0x01 << (7 - y + i));
        }
        if ((x - i >= 0) && (y + i) < 8) {
            board[x - i] |= (0x01 << (7 - y - i));
        }
        if ((x + i < 8) && (y - i) >= 0) {
            board[x + i] |= (0x01 << (7 - y + i));
        }
        if ((x + i < 8) && (y + i) < 8) {
            board[x + i] |= (0x01 << (7 - y - i));
        }
    }
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[]) {
    int x, y;
    unsigned char board[8] = {0};

    scanf("%d %d", &x, &y);

    wakanda_forever(x, y, board);

    for (size_t i = 0; i < 8; i++) {
        for (size_t ii = 0; ii < 8; ii++) {
            if (READ_BIT(board[i], 7 - ii))
                printf("X");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
