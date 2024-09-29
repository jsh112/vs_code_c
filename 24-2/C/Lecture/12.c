#include <stdio.h>

// 시우님 코드(답변)

int main(int argc, char const *argv[])
{
    char *str = "I am a boy";
    long long arr[12] = {(long long)"I am a boy"};

    if (arr[0] == str)
        printf("WoW\n");

    return 0;
}