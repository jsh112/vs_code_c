#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// diffs_len은 배열 diffs의 길이입니다.
// times_len은 배열 times의 길이입니다.
int solution(int diffs[], size_t diffs_len, int times[], size_t times_len, long long limit)
{
    int level = 1;
    long long time_sum = 0;
    while (1)
    {
        int time_prev = 0;
        time_sum = 0;
        for (int i = 0; i < diffs_len; i++)
        {
            int time_cur = times[i];
            if (diffs[i] <= level)
            {
                time_sum += time_cur;
            }
            else
            {
                time_sum += (diffs[i] - level) * (time_cur + time_prev) + time_cur;
            }
            if (time_sum > limit)
            {
                break;
            }
            time_prev = times[i];
        }
        if (time_sum <= limit)
        {
            return level;
        }
        level++;
    }
}

int main()
{

    int d[] = {1, 99999, 100000, 99995}, t[] = {9999, 9001, 9999, 9001};
    size_t len = 4;
    long long limit = 3456789012;

    printf("%d\n", solution(d, len, t, len, limit));

    return 0;
}