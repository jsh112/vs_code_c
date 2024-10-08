// 문제 F : 역순 출력

// 문제 설명
// 정수 N을 입력한다.
// 그 다음 줄에 N개의 정수를 입력한다.
// 입력한 N개의 정수들을 역순으로 출력하는 프로그램을 작성하시오.

// 입력 설명

// N
// A1 A2 A3 ... AN
// N(정수): 처리할 정수의 개수 (0 <= N < 101)
// A_i(정수): 처리할 정수들 (0 <= A_i <2^32, 1<= i <=N)

// 출력 설명
// 둘째 줄에 입력한 N개의 정수를 역순으로 출력한다.

// 입력 예시
// 4
// 1 4 8 32

// 출력 예시
// 32 8 4 1

// ACCEPTED CODE

#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    unsigned int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%u", &a[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%u ", a[i]);
    }

    return 0;
}