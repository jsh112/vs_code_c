#include <stdio.h>

int main() {
    int arr[8][8] = {0};

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int col[7] = {0};
    // 짝수비트를 가진 열을 찾아야함
    for (int i = 0; i < 7; i++) {
        int cnt = 0;
        for (int j = 0; j < 8; j++) {
            if (arr[j][i]) {
                cnt++;
            }
        }
        if (cnt % 2 == 0) {
            col[i] = 1;
        }
    }

    int row[7] = {0};
    // 짝수비트를 가진 행을 찾아야함
    for (int i = 0; i < 7; i++) {
        int cnt = 0;
        for (int j = 0; j < 8; j++) {
            if (arr[i][j]) {
                cnt++;
            }
        }
        if (cnt % 2 == 0) {
            row[i] = 1;
        }
    }

    int ii, jj;
    for (int i = 0; i < 7; i++) {
        if (row[i])
            ii = i;
        else if (col[i]) {
            jj = i;
        }
    }
    if (arr[ii][jj]) {
        arr[ii][jj] = 0;
    } else {
        arr[ii][jj] = 1;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}