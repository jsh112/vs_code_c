#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned int buildBitmask(char *str)
{
    unsigned int bitmask = 0;
    // 이 위로 수정 금지
    while (*str)
    {
        bitmask |= 0x01 << (*str - 'a');
        str++;
    }
    // 이 아래로 수정 금지
    return bitmask;
}

int main(int argc, char const *argv[])
{
    char str[104] = {0};
    unsigned int bitmask = 0;
    scanf("%s", str);
    bitmask = buildBitmask(str);
    printf("%X", bitmask);
    return 0;
}