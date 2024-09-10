#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned int data[100] = {0};
    for (int i = 0; i < 100; i++)
        scanf("%u", data + i);

    // 이 위로 수정 금지

    // 0 99 1 98 ... 49 50
    for (int j = 0; j < 50; j++)
    {
        int tmp = data[j];
        data[j] = data[99 - j];
        data[99 - j] = tmp;
    }
    // 이 아래로 수정 금지

    for (int i = 0; i < 100; i++)
        printf("%u ", data[i]);

    return 0;
}