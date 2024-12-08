#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct position {
    int x;   // 시작 위치 행 번호
    int y;   // 시작 위치 열 번호
    int dx;  // x 방향(아래 방향)인지, x 방향이면 1 아니면 0
    int dy;  // y 방향(우측 방향)인지, y 방향이면 1 아니면 0
};

// 이 위로 수정 금지
struct position find_word(char (*data)[8]) {
    struct position p;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (data[i][j] == 'a') {
                if (data[i][j + 1] == 'p' && j + 1 < 8) {
                    p.x = i;
                    p.y = j;
                    p.dx = 0;
                    p.dy = 1;
                    return p;
                }
                if (data[i + 1][j] == 'p' && i + 1 < 8) {
                    p.x = i;
                    p.y = j;
                    p.dx = 1;
                    p.dy = 0;
                    return p;
                }
            }
        }
    }
}
// 이 아래로 수정 금지

int main(int argc, char const *argv[]) {
    char data[8][8] = {0};
    for (size_t i = 0; i < 8; i++)
        for (size_t ii = 0; ii < 8; ii++)
            scanf(" %c", data[i] + ii);

    struct position pos = find_word(data);

    printf("%d %d %d %d", pos.x + 1, pos.y + 1, pos.dx, pos.dy);

    return 0;
}
