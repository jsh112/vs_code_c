#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void _sort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

int solution(int a, int b, int c, int d)
{
    int answer = 0, dice[4] = {a, b, c, d};
    _sort(dice, 4);
    if (dice[0] == dice[3])
    {
        // p, p, p, p
        answer = 1111 * dice[0];
    }
    else if ((dice[0] == dice[2]) || (dice[1] == dice[3]))
    {
        // p,p,p,q
        answer = (10 * dice[1] + (dice[0] + dice[3] - dice[1])) * (10 * dice[1] + (dice[0] + dice[3] - dice[1]));
    }
    else if ((dice[0] == dice[1]) && (dice[2] == dice[3]))
    {
        // p,p,q,q
        answer = (dice[1] + dice[2]) * (dice[2] - dice[1]);
    }
    else if ((dice[0] == dice[1]))
    {
        // p,p,q,r / q,p,p,r / q,r,p,p
        answer = dice[2] * dice[3];
    }
    else if ((dice[1] == dice[2]))
    {
        // p,p,q,r / q,p,p,r / q,r,p,p
        answer = dice[0] * dice[3];
    }
    else if ((dice[2] == dice[3]))
    {
        // p,p,q,r / q,p,p,r / q,r,p,p
        answer = dice[0] * dice[1];
    }
    else
    {
        // p,q,r,s
        answer = dice[0];
    }

    return answer;
}

int main()
{

    printf("%d\n", solution(2, 2, 2, 2));
    printf("%d\n", solution(4, 1, 1, 4));
    printf("%d\n", solution(6, 3, 3, 6));
    printf("%d\n", solution(2, 5, 2, 6));
    printf("%d\n", solution(6, 4, 2, 5));

    return 0;
}