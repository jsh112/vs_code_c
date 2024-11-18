#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void wakanda_forever(int x, int y, char *board) {
    // 이 위로 수정 금지

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i * 8 + j] = ' ';
        }
    }
    for (int i = 0; i < 8; i++) {
        if ((x - i >= 0) && (y - i) >= 0) {
            board[(x - i) * 8 + (y - i)] = 'X';
        }
        if ((x - i >= 0) && (y + i) < 8) {
            board[(x - i) * 8 + (y + i)] = 'X';
        }
        if ((x + i < 8) && (y - i) >= 0) {
            board[(x + i) * 8 + (y - i)] = 'X';
        }
        if ((x + i < 8) && (y + i) < 8) {
            board[(x + i) * 8 + (y + i)] = 'X';
        }
    }

    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[]) {
    int x, y;
    char board[8][8] = {0};

    scanf("%d %d", &x, &y);

    wakanda_forever(x, y, (char *)board);

    for (size_t i = 0; i < 8; i++) {
        for (size_t ii = 0; ii < 8; ii++) {
            printf("%c", board[i][ii]);
        }
        printf("\n");
    }

    return 0;
}
