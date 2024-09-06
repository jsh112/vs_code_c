// 문제 C - 비트 연산의 기초 AND

// 문제 설명
// 입력한 N의 가장 아래 비트(LSB)의 값을 0으로 바꾸어 출력하시오.
// 입력 설명

// N(정수): 처리할 정수 (0 <= N < 2^32)

// 출력 설명
// 입력한 수에서 가장 아래 비트(LSB)를 0으로 바꾼 수를 출력한다.
// 입력 예시
// 11
// 출력 예시
// 10

#include <stdio.h>

int main()
{

    unsigned int N;
    scanf("%u", &N);

    printf("%u\n", N & 0xFFFFFFFE);

    return 0;
}