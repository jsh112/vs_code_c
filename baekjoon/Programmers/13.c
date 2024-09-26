#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char *number)
{
    int answer = 0, len = 0, sum;
    while (number[len] != '\0')
    {
        len++;
    }
    for (int i = 0; i < len; i++)
    {
        sum += (number[i] - '0');
    }
    answer = sum % 9;
    return answer;
}

int main()
{

    printf("%d\n", solution("78720646226947352489"));

    return 0;
}