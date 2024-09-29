// 1차원 배열에 담긴 10개의 값들과 인덱스 a를 입력받는다.
// 모든 배열 요소들 순서대로 탐색하여
// a인덱스에 있는 값보다 작은 값을 찾아서, 두 값을 교체한다.
// 반복적으로 수행하면, 결과적으로 가장 작은 요소값이
// 인덱스에 위치하게 된다.

// 아래의 코드를 수정하여 배열과 인덱스를 인자로 받아 위의 설명에 따라 교환하는 함수를 작성하시오.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
void changeArr(unsigned int arr[], unsigned int a)
{
    unsigned int std;
    for (int i = 0; i < 10; i++)
    {
        std = *(arr + a);
        if (arr[i] < std)
        {
            unsigned int tmp = std;
            *(arr + a) = arr[i];
            *(arr + i) = tmp;
        }
    }
}

// void changeArr(unsigned int arr[], unsigned int a)
// {
//     unsigned int std = arr[a];
//     for (int i = 0; i < 10; i++)
//     {
//         if (std > arr[i])
//         {
//             unsigned int tmp = std;
//             std = arr[i];
//             arr[i] = tmp;
//             std = tmp;
//         }
//     }
// }
// 이 아래로 수정 금지

int main()
{
    unsigned int arr[10];
    unsigned int a;

    // 배열 요소와 인덱스 a를 입력받는다
    for (unsigned int i = 0; i < 10; i++)
    {
        scanf("%u", &arr[i]);
    }
    scanf("%u", &a);

    changeArr(arr, a);

    // 수정된 배열 출력
    for (unsigned int i = 0; i < 10; i++)
    {
        printf("%u ", arr[i]);
    }

    return 0;
}