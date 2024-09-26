#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int gain_num(int bin)
{
    int decimal = 1, sum = 0;
    for (int i = 0; i < 18; i++)
    {
        sum += ((bin >> i) & 0x01) * decimal;
        decimal *= 10;
    }
    return sum;
}

int *solution(int l, int r)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int *answer = (int *)malloc(sizeof(int) * 1000);
    int cnt = 0, bin_0 = 1;
    answer[cnt] = -1;
    while ((l / 5) > gain_num(bin_0))
    {
        bin_0++;
    }
    int num = 5 * gain_num(bin_0);
    while (num >= l && num <= r)
    {
        answer[cnt++] = num;
        num = 5 * gain_num(++bin_0);
    }
    return answer;
}

int main()
{

    int r = 1000, l = 48;
    int *a = solution(l, r);

    return 0;
}