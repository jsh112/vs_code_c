#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지

int my_strcmp(char* d, char* s){
    while(*d && *s && *d == *s) {
        d++;
        s++;
    }
    return *d - *s;
}

char* my_strcpy(char* dest, const char* src){
    char* tmp = dest;
    while(*src){
        *tmp = *src;
        tmp++;
        src++;
    }
    *tmp = 0;
    return dest;
}

void checkout_bingo(char **board, char **name, int N) {
    char(*bingo_board)[3][12] = (char(*)[3][12])board;
    char(*called_name)[12] = (char(*)[12])name;

    for (int n = 0; n < N; n++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (my_strcmp(bingo_board[i][j], called_name[n]) == 0) {
                    my_strcpy(bingo_board[i][j], ".");  
                }
            }
        }
    }
}

// 이 아래로 수정 금지

int main(int argc, char const *argv[]) {
    char bingo_board[3][3][12] = {0};
    unsigned int N = 0;
    char called_name[100][12] = {0};

    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            scanf("%s", bingo_board[i][j]);
    scanf("%u", &N);

    for (size_t i = 0; i < N; i++)
        scanf("%s", called_name[i]);

    checkout_bingo((char *)bingo_board, (char *)called_name, N);

    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            printf("%s%c", bingo_board[i][j], (j == 2 ? '\n' : ' '));

    return 0;
}