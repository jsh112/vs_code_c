#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char *solution(const char *my_strings[], size_t my_strings_len, int **parts, size_t parts_rows, size_t parts_cols)
{
    char *answer = (char *)malloc(10000);
    int cnt = 0;
    for (int i = 0; i < parts_rows; i++)
    {
        int s = parts[i][0], e = parts[i][1];
        for (; s <= e; s++)
        {
            answer[cnt++] = my_strings[i][s];
        }
    }
    answer[cnt++] = '\0';
    answer = (char *)realloc(answer, cnt);
    return answer;
}