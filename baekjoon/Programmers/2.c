#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int *solution(int num_list[], size_t num_list_len, int n)
{
    return num_list + (n - 1);
}

int main()
{

    int arr[] = {5, 2, 1, 7, 5};
    int n = 2;
    int len = 5;
    int *p = solution(arr, len, n);
    for (int i = 0; i < (len - n + 1); i++)
    {
        printf("%d ", p[i]);
    }

    return 0;
}