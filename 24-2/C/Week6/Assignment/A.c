#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned char *checkBytes(unsigned int *numPtr, unsigned int order)
{
    // 이 위로 수정 금지
    return (unsigned char *)numPtr + order;
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[])
{
    unsigned int num;

    scanf("%X", &num);
    for (int i = 3; i >= 0; i--)
    {
        unsigned char *ptr = checkBytes(&num, i);
        printf("%X ", *ptr);
    }

    return 0;
}