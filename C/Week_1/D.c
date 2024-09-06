#include <stdio.h>

int main(void)
{
    // N : (정수): 음악 플레이리스트에 담겨있는 곡의 개수
    // a : 곡번호(정수): 곡 번호
    // b : 곡마다 들은 회수(정수): 곡마다 들은 횟수

    int n;
    scanf("%d", &n);
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (b[i] <= 5)
        {
            printf("%d ", a[i]);
        }
    }

    return 0;
}