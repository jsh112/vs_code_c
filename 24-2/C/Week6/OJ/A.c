#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_various_mass(unsigned int num)
{
    // 이 위로 수정 금지
    unsigned char a = num & 0xFF;
    unsigned short b = num & 0xFFFF;
    unsigned int c = num & 0xFFFFFFFF;
    printf("%X %X %X", a, b, c);
    // 이 아래로 수정 금지
    return;
}

int main(int argc, char const *argv[])
{
    unsigned int data;
    scanf("%X", &data);
    print_various_mass(data);
    return 0;
}