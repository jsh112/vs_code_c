// 배열의 시작 주소가 0x1000번지인 2차원 int배열
// int arr[A][B]이 존재할 때,
// 특정 인덱스의 주소를 출력하는 프로그램을 작성하시오.

// N M A B
// N : (정수) : arr의 첫번째 차원의 크기
// M : (정수) : arr의 두번째 차원의 크기
// A : (정수) : 주소를 출력할 공간의 첫번째 인덱스
// B : (정수) : 주소를 출력할 공간의 두번째 인덱스

// 1<= N, M <= 100
// 0 <= A < N, 0 <= B < M

#include <stdio.h>

int main()
{

    int N, M, A, B;
    scanf("%d %d %d %d", &N, &M, &A, &B);

    printf("%X\n", 0x1000 + sizeof(int) * ((M * A) + B));

    return 0;
}