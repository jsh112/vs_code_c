// 문제 N : 삭제

// 문제 설명
// 아래의 코드를 수정하여 숫자를 담은 배열에서 입력한 인덱스에 위치한 요소 1개를 삭제하는 함수 deleteValue를 작성하시오.
// 배열의 크기는 10에서 삭제했을 때 9이다.

// **주의**
// 수정 가능한 부분만 수정하시오. 수정 불가 영역 건들면 부정행위로 간주함.

// 입력 설명

// A1 A2 ... A10
// N

// Ai(정수): 처리할 배열
// N(정수): 삭제할 인덱스

// 0 <= Ai < 2^32 (1 <= i <= N)
// 0 <= N < 10

// 출력 설명
// 원하는 요소가 삭제된 배열을 출력한다.

// 입력 예시
// 0 1 2 3 4 5 6 7 8 9
// 3
// 출력 예시
// 0 1 2 4 5 6 7 8 9

// ACCEPTED CODE

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
void deleteValue(unsigned int arr[], unsigned int index)
{
    for (int i = index; i < 9; i++)
    {
        arr[i] = arr[i + 1];
    }
}
// 이 아래로 수정 금지

int main(void)
{
    unsigned int arr[10];
    unsigned int index;

    for (int i = 0; i < 10; i++)
    {
        scanf("%u", &arr[i]);
    }

    scanf("%u", &index);

    deleteValue(arr, index);

    for (int i = 0; i < 9; i++)
    {
        printf("%u ", arr[i]);
    }

    return 0;
}