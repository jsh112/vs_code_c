// 문제 G : XOR gate

// 문제 설명
// 음이 아닌 정수 A, B를 차례로 입력한다.

// 입력한 두 개의 정수 A와 B를 AND 연산한 뒤 NOT 연산한 값을 C로 저장한다.
// 그리고
// A와 B를 OR 연산한 값을 D로 저장한다.
// 마지막으로 C와 D를 AND 연산한 값을 Q로 저장한다.
// C, D, Q를 차례로 출력하라.

// 입력 설명

// A B

// A(정수): 처리할 정수
// B(정수): 처리할 정수
// (0 <= A, B < 2^32)

// 출력 설명
// 입력한 값 2개를
// 1) AND 연산한 뒤 NOT 연산한 값,
// 2) OR 연산한 값,
// 3) 마지막으로 두 가지 결과값으로 AND 연산한 값을

// 띄어쓰기로 구분하여 차례대로 출력하시오.

#include <stdio.h>

int main()
{

    unsigned int A, B;
    scanf("%u %u", &A, &B);
    unsigned int C = ~(A & B);
    unsigned int D = (A | B);
    unsigned int Q = C & D;

    printf("%u %u %u\n", C, D, Q);

    return 0;
}