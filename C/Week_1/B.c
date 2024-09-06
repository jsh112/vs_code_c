#include <stdio.h>

// 이 위로 수정 금지
void my_swap(unsigned int *a, unsigned int *b)
{
    unsigned int tmp = *a;
    *a = *b;
    *b = tmp;
}
// 이 아래로 수정 금지

int main(void)
{
    unsigned int a, b;
    scanf("%u %u", &a, &b);
    my_swap(&a, &b);
    printf("%d %d", a, b);

    return 0;
}