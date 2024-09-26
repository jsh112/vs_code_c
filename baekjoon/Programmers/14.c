#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// queries_rows는 2차원 배열 queries의 행 길이, queries_cols는 2차원 배열 queries의 열 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char *solution(const char *my_string, int **queries, size_t queries_rows, size_t queries_cols)
{
    // my_string의 길이 계산
    int len = 0;
    while (my_string[len] != '\0')
    {
        len++;
    }

    // answer를 동적 할당 및 초기화
    char *answer = (char *)malloc(sizeof(char) * (len + 1));
    for (int j = 0; j < len; j++)
    {
        answer[j] = my_string[j];
    }
    answer[len] = '\0';
    for (size_t i = 0; i < queries_rows; i++)
    {
        int start = queries[i][0];
        int end = queries[i][1];

        while (start < end)
        {
            char tmp = answer[start];
            answer[start] = answer[end];
            answer[end] = tmp;
            start++;
            end--;
        }
    }

    return answer;
}

int main()
{
    int rows = 5, cols = 2;
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    arr[0][0] = 2;
    arr[0][1] = 3;
    arr[1][0] = 0;
    arr[1][1] = 7;
    arr[2][0] = 5;
    arr[2][1] = 9;
    arr[3][0] = 6;
    arr[3][1] = 10;

    printf("%s\n", solution("rermgorpsam", arr, 4, 2));

    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}