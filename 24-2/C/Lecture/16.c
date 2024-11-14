#include <stdio.h>
#include <stdlib.h>
/*
void set(char **q) {
    // static char
    static char *str1 = "ABCDE";
    static char *str2 = "1234567";

    *q = str2;
}

int main() {
    char *s = "111111111111";
    set(&s);

    printf("%s\n", s);
    return 0;
} */

void malloc_1() {
    int **pp = (int **)malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++) {
        *(pp + i) = (int *)malloc(sizeof(int) * 4);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            pp[i][j] = i + j;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", pp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void malloc_2() {
    // 하나의 덩어리로 만들기
}

void print_data(int (*p)[3][4]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                printf("%d ", p[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    /* malloc_1();

    malloc_2(); */

    /* char *fruits[] = {
                "apple",
                "kiwi",
                "orange",
                "melon"
        };

    printf("%s\n", fruits[0]);
    printf("%c\n",fruits[0][0]); */

    int arr[2][3][4];
    int cnt = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                arr[i][j][k] = cnt;
                cnt++;
            }
        }
    }
    print_data(arr);

    return 0;
}
