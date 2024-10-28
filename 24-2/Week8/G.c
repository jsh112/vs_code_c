#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void cuttingCake(unsigned int *cake) {
    // 이 위로 수정 금지

    /*
     * (0,4)
     * (1,3), (1,5)
     * (2,2), (2,6)
     * (3,1), (3,7)
     * (4,0), (4,8)
     * 
     * (5,1), (5,7)
     * (6,2), (6,6)
     * (7,3), (7,5)
     * (8,4)
     */

    // i : 1, j : 3
    // idx : 12 
    // 
    // *(cake + 1) -> 1 * sizeof(unsigned int)
    // double* cake
    // *(cake + j) -> &cake + sizeof(double) * j 
    int i = 0;
    for (; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if ((i + j == 4) || (j - i == 4)) {
                cake[9 * i + j] = 0;
            }
        }
    }

    for (; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if ((i - j == 4) || (i + j == 12)) {
                cake[9 * i + j] = 0;
            }
        }
    }

    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[]) {
    unsigned int cake[9][9] = {0};
    for (size_t i = 0; i < 9; i++) {
        for (size_t j = 0; j < 9; j++) {
            scanf("%u", &cake[i][j]);
        }
    }

    cuttingCake((unsigned int *)cake);

    for (size_t i = 0; i < 9; i++) {
        for (size_t j = 0; j < 9; j++) {
            if (cake[i][j] == 0) {
                printf("  ");
            } else {
                printf("%u ", cake[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}