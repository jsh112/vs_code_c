#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define READ_BIT(X, N) (((X) >> (N)) & 1)

// 이 위로 수정 금지
void square(int x, int y, int n, unsigned int* b) {
    // 3 2 2
    // (3,2) (3,3) (3,4)
    // (3,2),(4,2), (5,2)
    // (4,4),(5,4)
    // (5,3), (5,4)

    for (int i = x; i <= x + n; i++) {
        for (int j = y; j <= y + n; j++) {
            b[i] |= (0x01 << (7 - y));
        }
    }
}
// 이 아래로 수정 금지

int main(int argc, char const* argv[]) {
    int x, y, n;
    unsigned int board[32] = {0};

    scanf("%d %d %d", &x, &y, &n);

    square(x, y, n, board);

    for (size_t i = 0; i < 32; i++) {
        for (size_t ii = 0; ii < 32; ii++) {
            if (READ_BIT(board[i], 32 - ii))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
