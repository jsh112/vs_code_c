#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct S
{
    unsigned int i;
    char str[12];
    float f;
};

void struct_swap(struct S *lhs, struct S *rhs)
{
    // 이 위로 수정 금지
    struct S tmp;
    tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[])
{
    struct S S1, S2;
    scanf("%u %s %f", &S1.i, S1.str, &S1.f);
    scanf("%u %s %f", &S2.i, S2.str, &S2.f);

    struct_swap(&S1, &S2);

    printf("%u %s %.2f\n", S1.i, S1.str, S1.f);
    printf("%u %s %.2f\n", S2.i, S2.str, S2.f);

    return 0;
}