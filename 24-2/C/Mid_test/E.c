#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char *my_itoa(char *str, int value)
{
    // 이 위로 수정 금지
    int len = 0;
    char *tmp = str;
    int arr[100] = {0};
    int i = 0;
    while (value != 0)
    {
        arr[i] = (value % 10);
        value /= 10;
        tmp++;
        len++;
    }

    
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[])
{
    char S[101] = {0};
    int I;

    scanf("%d", &I);

    printf("%s", my_itoa(S, I));

    return 0;
}