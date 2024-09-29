#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 마법의 엘레베이터

int solution(int storey)
{
    int answer = 0;
    while (storey != 0)
    {
        int m = storey % 10;
        storey /= 10;
        if (m > 5)
        {
            answer += (10 - m);
            storey += 1;
        }
        else if (m < 5)
        {
            answer += m;
        }
        else
        {
            // m == 5
            if (storey % 10 == 5)
            {
                if (storey / 10 == 0)
                {
                    storey -= 1;
                }
                else
                {
                    storey += 1;
                }
            }
            answer += 5;
        }
    }
    return answer;
}

int main()
{

    printf("%d\n", solution(16));
    printf("%d\n", solution(2554));
    printf("%d\n", solution(4544));
    printf("%d\n", solution(6535));
    printf("%d\n", solution(6575));
    return 0;
}