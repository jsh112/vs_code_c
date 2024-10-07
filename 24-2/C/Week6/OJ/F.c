#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void changeCharAt(char *str, unsigned int index, char newChar)
{
    // 이 위로 수정 금지
    str[index] = newChar;
    // 이 아래로 수정 금지
}

//======== main 문 수정 금지 ========
int main(int argc, char const *argv[])
{
    char str[100];
    unsigned int index;
    char newChar;

    scanf("%[^\n]s", str);
    scanf("%u %c", &index, &newChar);

    changeCharAt(str, index, newChar);

    // 변경된 문자열 출력
    printf("%s", str);

    return 0;
}