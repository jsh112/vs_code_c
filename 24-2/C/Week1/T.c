// 문제 T : 익명2

// 문제 설명
// 문자열에 주어진 문자가 있을 경우 '#'로 바꾸는 프로그램을 작성하시오.
// 입력 설명

// S
// T

// S(문자열) : 공백이 포함된 문자열
// T(문자) : '#'으로 바꿀 문자
// length(S) < 101

// 출력 설명
// 문자열 S에서 주어진 문자 T가 있을 경우 '#'으로 바꾼 결과를 출력한다.

// 입력 예시
// coconut oil so good
// o
// 출력 예시
// c#c#nut #il s# g##d

// ACCEPTED CODE

#include <stdio.h>

int main()
{

    char s[101], t;
    gets(s);
    scanf("%c", &t);
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }

    for (int i = 0; i < len; i++)
    {
        if (s[i] == t)
        {
            printf("#");
        }
        else
        {
            printf("%c", s[i]);
        }
    }

    return 0;
}