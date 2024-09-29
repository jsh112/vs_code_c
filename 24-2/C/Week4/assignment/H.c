// 문자열을 입력받아 알파벳을 2단계 높여서 출력하시오.
// 예를 들어 'A'는 'C'로 바꾸고, 'H'는 'J'로 바꾸어 출력한다.
// 단, 'Y'는 'A'로 바꾸고 'Z'는 'B'로 바꾼다.

// 입력 : FYNNW
// 출력 : HAPPY

#include <stdio.h>

int main()
{

    char s[101];
    gets(s);
    int len = 0, alpha_num = 26;
    while (s[len] != '\0')
    {
        len++;
    }
    for (int i = 0; i < len; i++)
    {
        printf("%c", (s[i] - 'A' + 2) % alpha_num + 'A');
    }

    return 0;
}