#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
long long *solution(long long numbers[], size_t numbers_len)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    long long *answer = (long long *)malloc(sizeof(long long) * numbers_len);
    for (size_t i = 0; i < numbers_len; i++)
    {
    }
    return answer;
}

int main()
{

    return 0;
}