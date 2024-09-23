#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// queries_rows는 2차원 배열 queries의 행 길이, queries_cols는 2차원 배열 queries의 열 길이입니다.
int *solution(int arr[], size_t arr_len, int **queries, size_t queries_rows, size_t queries_cols)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int *answer = (int *)malloc(sizeof(int) * queries_rows);
    for (int i = 0; i < queries_rows; i++)
    {
        int min1 = queries[i][2];
        int min2 = 1000000;
        for (int j = queries[i][0]; j <= queries[i][1]; j++)
        {
            if (arr[j] > min1 && arr[j] < min2)
            {
                min2 = arr[j];
            }
        }
        if (min2 == 1000000)
            answer[i] = -1;
        else
        {
            answer[i] = min2;
        }
    }
    return answer;
}

int main()
{

    int arr[] = {0, 1, 2, 4, 3};
    size_t queries_rows = 3;
    size_t queries_cols = 3;

    // Allocate memory for the 2D array
    int **q = (int **)malloc(queries_rows * sizeof(int *));
    for (size_t i = 0; i < queries_rows; i++)
    {
        q[i] = (int *)malloc(queries_cols * sizeof(int));
    }

    // Initialize the 2D array
    int data[][3] = {{0, 4, 2}, {0, 3, 2}, {0, 2, 2}};
    for (size_t i = 0; i < queries_rows; i++)
    {
        for (size_t j = 0; j < queries_cols; j++)
        {
            q[i][j] = data[i][j];
        }
    }

    int *k = solution(arr, 5, q, queries_rows, queries_cols);

    // Print the results
    for (size_t i = 0; i < queries_rows; i++)
    {
        printf("%d\n", k[i]);
    }

    // Free allocated memory for the 2D array
    for (size_t i = 0; i < queries_rows; i++)
    {
        free(q[i]);
    }
    free(q);

    // Free allocated memory for the answer array
    free(k);

    return 0;
}