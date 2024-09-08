// 문제 I : 줄임말

// 문제 설명
// 공백이 포함된 문장을 입력하면, 대문자만 골라 출력하는 프로그램을 작성하시오.
// 입력 설명
// S
// S(문자열): 처리할 문장
// (0 <= length(S) < 101)

// 출력 설명
// 문자열 중 대문자만 고른 줄임말을 출력하라.

// 입력 예시
// Hi Guys. Nice To Meet You.
// 출력 예시
// HGNTMY

// Hint
// 힌트1:
// gets(str)

// 위의 함수를 사용하면, 문자열 변수 str에 공백을 포함해서 입력받을 수 있다.

// 힌트2:
// 문자열의 끝에 NULL 문자가 있어야 %s로 출력할 수 있다.

// ACCEPTED CODE

#include <stdio.h>

int my_strlen(const char *str);

int main()
{

    char str[101];
    gets(str);
    for (int i = 0; i < my_strlen(str); i++)
    {
        if ((str[i] >= 'A') && (str[i] <= 'Z'))
        {
            printf("%c", str[i]);
        }
    }

    return 0;
}

int my_strlen(const char *str)
{
    int cnt = 0;
    while (str[cnt] != '\0')
    {
        cnt++;
    }
    return cnt;
}