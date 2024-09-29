#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int *solution(int arr[], size_t arr_len)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int *stk = (int *)malloc(sizeof(int) * arr_len);
    size_t iter = 0, i = 0;
    while (i < arr_len)
    {
        if (iter == 0)
        {
            stk[iter] = arr[i];
            i++;
            iter++;
        }
        else
        {
            if (stk[iter] < arr[i])
            {
                stk[iter] = arr[i];
                i++;
            }
            else
            {
                stk[iter] = 0;
            }
        }
    }
    return stk;
}

int main()
{

    int arr[] = {1, 4, 2, 5, 3};
    int *a = solution(arr, 5);

    return 0;
}