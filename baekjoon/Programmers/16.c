#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char *s)
{
    bool answer = true;
    int len = 0;
    while (s[len++] != '\0')
        ;
    // len is odd or s[0] is ')'
    if ((len % 2 != 0) || s[0] == ')')
    {
        return false;
    }
    else if (s[len - 1] == '(')
    {
        return false;
    }

    // First, '(' and ')' numbers same
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
    }
    if (cnt1 != cnt2)
    {
        return false;
    }

    int c1 = 0, c2 = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            c1++;
        }
        else
        {
            c2++;
        }

        if (c1 < c2)
        {
            return false;
        }
    }

    return answer;
}

int main()
{

    printf("%d\n", solution("()()"));
    printf("%d\n", solution("(())()"));
    printf("%d\n", solution("(())()"));
    printf("%d\n", solution(")()("));
    printf("%d\n", solution("(()("));

    return 0;
}
