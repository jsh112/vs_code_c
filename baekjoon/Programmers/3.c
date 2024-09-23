#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// delete_list_len은 배열 delete_list의 길이입니다.
int *solution(int arr[], size_t arr_len, int delete_list[], size_t delete_list_len)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int cnt = 0;
    int *answer = (int *)malloc(sizeof(int) * arr_len);
    int flag = 0;
    for (int i = 0; i < arr_len; i++)
    {
        for (int j = 0; j < delete_list_len; j++)
        {
            if (arr[i] == delete_list[j])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            flag = 0;
            answer[cnt++] = arr[i];
        }
        flag = 0;
    }
    return answer;
}

int main()
{

    int a[] = {293, 1000, 395, 1};
    int d[] = {94, 777, 104, 1000, 1, 12};
    size_t a_len = 4, d_len = 6;
    int *p = solution(a, a_len, d, d_len);

    return 0;
}