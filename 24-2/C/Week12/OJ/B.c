#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
void swap_double_ptr(int*** p1, int*** p2){
    int** tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void swap_ptr(int **p1, int** p2){
    int* tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void swap_int(int *p1, int* p2){
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
// 이 아래로 수정 금지

int main(int argc, int const *argv[])
{
    int a, b, c, d;
    int *pa = &a;
    int *pb = &b;
    int *pc = &c;
    int *pd = &d;
    int **ppa = &pa;
    int **ppb = &pb;
    int **ppc = &pc;
    int **ppd = &pd;
    scanf("%d%d%d%d", pa, pb, pc, pd);

    swap_double_ptr(&ppa, &ppb);
    swap_ptr(&pb, &pc);
    swap_int(&c, &d);

    printf("%d %d %d %d\n", a, b, c, d);
    printf("%d %d %d %d\n", *pa, *pb, *pc, *pd);
    printf("%d %d %d %d\n", **ppa, **ppb, **ppc, **ppd);
    return 0;
}
