#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char *str1, const char *str2)
{
    int answer = 1;
    int len1 = 0, len2 = 0;
    while (str1[len1] != '\0')
    {
        len1++;
    }
    while (str2[len2] != '\0')
    {
        len2++;
    }
    for (int i = 0; i <= len2 - len1; i++)
    {
        for (int j = 0; j < len1; j++)
        {
            if (str1[j] != str2[j + i])
            {
                answer = 0;
                break;
            }
        }
        if (answer)
        {
            return answer;
        }
    }
    return answer;
}

int main()
{

    const char *str1 = "abc", *str2 = "aabcc";
    printf("%d\n", solution(str1, str2));
    return 0;
}