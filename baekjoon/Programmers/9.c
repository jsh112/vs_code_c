#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char *solution(const char *code)
{
    int len = 0, mode = 0, iter = 0;
    while (code[len] != '\0')
    {
        len++;
    }
    char *answer = (char *)malloc(sizeof(char) * (len / 2 + 1));
    const char *ptr = code;
    // for (int i = 0; i < len; i++)
    // {
    //     if (code[i] == '1')
    //     {
    //         mode = !mode;
    //         continue;
    //     }
    //     if (mode == 0)
    //     {
    //         if (i % 2 == 0)
    //         {
    //             answer[iter++] = code[i];
    //         }
    //     }
    //     else
    //     {
    //         if (i % 2 != 0)
    //         {
    //             answer[iter++] = code[i];
    //         }
    //     }
    // }

    while (*ptr != '\0')
    {
        if (*ptr == '1')
        {
            mode = !mode;
            ptr++;
            continue;
        }
        if ((ptr - code) % 2 == 0 && mode == 0)
        {
            answer[iter++] = *ptr;
        }
        else if ((ptr - code) % 2 != 0 && mode == 1)
        {
            answer[iter++] = *ptr;
        }
        ptr++;
    }

    answer[iter] = '\0';
    if (iter == 0)
    {
        answer = "EMPTY\0";
    }
    return answer;
}

int main()
{

    char code[500] = "abc1abc1abc";
    printf("%s\n", solution(code));

    return 0;
}