// 배열의 시작 주소가 0x1000번지인 2차원 int배열
// int arr[6][5]가 존재할 때,
// 입력한 주소를 참조하기 위한 인덱스를 출력하는 프로그램을 작성하시오.
// 단, 첫번째 인덱스가 최대인 경우를 출력한다.

// A (정수) : 참조하고 싶은 주소, 대문자 16진수
// 0x1000 <= A < 0x1078
// A = 4 X N (N은 0 이상의 정수)

#include <stdio.h>

int main()
{

    int A;
    scanf("%x", &A);

    int a1 = (A - 0x1000) / (sizeof(int) * 5);
    A -= a1 * (sizeof(int) * 5);
    int a2 = (A - 0x1000) / sizeof(int);
    printf("%d %d", a1, a2);

    return 0;
}