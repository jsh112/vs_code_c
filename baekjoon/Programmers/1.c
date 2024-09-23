//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int calc(int a, int b)
{
    int size = 1;
    while (size <= b)
        size *= 10;
    return a * size + b;
}
int solution(int a, int b)
{
    int ab = calc(a, b), ba = calc(b, a);
    int answer = ab;
    if (ba > ab)
        answer = ba;
    return answer;
}