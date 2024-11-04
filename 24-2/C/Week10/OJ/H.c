#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
void pointer_swap(int **ppa, int** ppb){
    int* tmp;
    tmp = *ppa;
    *ppa = *ppb;
    *ppb = tmp;
}
// 이 아래로 수정 금지

int main(int argc, char const *argv[])
{
    int A, B;
    int *pa = &A, *pb = &B;
    scanf("%d %d", pa, pb);
    pointer_swap(&pa, &pb);
    printf("%d %d", *pa, *pb);
    return 0;
}