#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char *solution(int numLog[], size_t numLog_len)
{
    char *answer = (char *)malloc(numLog_len);
    int idx = numLog_len - 1;
    answer[idx] = '\0';
    for (; idx > 0; idx--)
    {
        int n = numLog[idx] - numLog[idx - 1];
        if (n == 1)
            answer[idx - 1] = 'w';
        else if (n == -1)
            answer[idx - 1] = 's';
        else if (n == 10)
            answer[idx - 1] = 'd';
        else if (n == -10)
            answer[idx - 1] = 'a';
    }
    return answer;
}