#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// int power(int x)
// {
//     int n = 1;
//     for (int i = 0; i < x - 1; i++)
//     {
//         n *= 10;
//     }
//     return n;
// }

// // 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// int solution(const char *n_str)
// {
//     int len = 0;
//     const char *ptr = n_str;
//     while (*ptr != '\0')
//     {
//         len++;
//         ptr++;
//     }
//     int answer = 0, i = power(len);
//     while (*n_str != '\0')
//     {
//         answer += (*n_str - '0') * i;
//         i /= 10;
//         n_str++;
//     }

//     return answer;
// }

int solution(const char *n_str)
{
    int answer = 0;
    const char *ptr = n_str;
    while (*ptr != '\0')
    {
        answer = 10 * answer + (*ptr - '0');
        ptr++;
    }
    return answer;
}

int main()
{

    printf("%d\n", solution("8542"));

    return 0;
}