#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void getByte(unsigned int *num)
{
    // 이 위로 수정 금지
    *num = *num & 0xFF000000;
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[])
{
    unsigned int num;

    scanf("%X", &num);
    getByte(&num);

    printf("%X", num);

    return 0;
}