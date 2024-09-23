#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char *solution(const char *my_string, const char *overwrite_string, int s)
{
    // 문자열 길이 계산
    int len1 = 0;
    int len2 = 0;

    while (my_string[len1] != '\0')
    {
        len1++;
    }
    while (overwrite_string[len2] != '\0')
    {
        len2++;
    }
    char *answer = (char *)malloc((len1 + 1) * sizeof(char));

    // my_string의 첫 부분 복사
    for (int i = 0; i < s; i++)
    {
        answer[i] = my_string[i];
    }

    // overwrite_string 복사
    for (int j = s; j < s + len2; j++)
    {
        answer[j] = overwrite_string[j - s];
    }

    // my_string의 나머지 부분 복사
    for (int k = s + len2; k < len1; k++)
    {
        answer[k] = my_string[k];
    }
    answer[len1] = '\0';

    return answer;
}

int main()
{

    const char *m_string = "Program29b8UYP";
    const char *ov_string = "merS123";
    int s = 7;
    printf("%s\n", solution(m_string, ov_string, s));

    return 0;
}