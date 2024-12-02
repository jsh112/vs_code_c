#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
void set_ptrarr(int* arr, int** parr){
    for (int i = 0; i < 3; i++){
        parr[i] = arr + 3 * i;
    }
}
// 이 아래로 수정 금지

int main(int argc, char const *argv[])
{
    unsigned int arr[9] = {0};
    unsigned int *parr[3] = {0};

    set_ptrarr(arr, parr);

    for (size_t i = 0; i < 9; i++)
        scanf("%u", arr + i);

    for (size_t i = 0; i < 3; i++)
        for (size_t ii = 0; ii < 3; ii++)
            printf("%u%c", parr[i][ii], ii == 2 ? '\n' : ' ');

    return 0;
}
