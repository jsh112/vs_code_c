// // 문제 l : 문자열 검색

// 문제 설명
// 공백이 포함된 문자열 str, word를 입력한다.
// str에 word가 존재하는 지 검사하는 프로그램을 작성하시오.

// 입력 설명

// S
// W

// S(문자열): 문장 str
// W(문자열): 문장 word

// 1 <= length(S) < 101
// 1 <= length(W) < 101

// 출력 설명
// str에 word가 존재한다면 word와 '!'를 출력한다.
// 존재하지 않는다면, word와 '?'를 출력한다.

// 입력 예시
// hello world!
// world
// 출력 예시
// world!

// ACCEPTED CODE

#include <stdio.h>

int my_len(const char *str)
{
    int cnt = 0;
    while (str[cnt] != '\0')
    {
        cnt++;
    }
    return cnt;
}

int main()
{
    const int sz = 101;
    char s[sz], w[sz];
    gets(s);
    gets(w);

    // len(S) < len(W) : not case
    int len_s = my_len(s);
    int len_w = my_len(w);
    if (len_s < len_w)
    {
        printf("%s?", w);
        return 0;
    }
    // len(S) >= len(W)
    for (int i = 0; i <= len_s - len_w; i++)
    {
        int j;
        for (j = 0; j < len_w; j++)
        {
            if (s[i + j] != w[j])
            {
                break;
            }
        }
        if (j == len_w)
        {
            printf("%s!", w);
            return 0;
        }
    }
    printf("%s?\n", w);
    return 0;
}