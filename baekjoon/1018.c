#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    // (8 <= n, m <= 50)
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();
    char p[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &p[i][j]);
        }
        getchar();
    }
    // 8x8 배열은 n, m일 때 (n - 7) * (m - 7)개로 구성
    // 9x9 -> 2 * 2 -> 4
    // 10 * 13 -> 3 * 6 = 18
    // 9*9라고 하면 0 ~ 2 / 0 ~ 2를 조사

    int _min = 64;
    int _w = 0;
    int _b = 0;
    for (int num1 = 0; num1 < (n - 7); num1++)
    {
        for (int num2 = 0; num2 < (m - 7); num2++)
        {
            // 이제 체스판 하나를 잘라냈음
            // 이제 여기서 7칸(0 ~ 7까지 조사해봐야함)
            // 첫 시작이 B인지 W인지 골라야함
            // 만약 p[num1][num2]가 W이면
            // (num1 + num2)가 짝수일 때 합이 홀수이면 모두 B

            // 흰색을 칠할 지 검은색을 칠할 지
            // 최솟값을 정하기 위함
            _w = 0;
            _b = 0;
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if ((i + j) % 2 == 0)
                    {
                        if (p[num1 + i][num2 + j] != 'W')
                            _w++;
                        if (p[num1 + i][num2 + j] != 'B')
                            _b++;
                    }
                    else
                    {
                        if (p[num1 + i][num2 + j] != 'B')
                            _w++;
                        if (p[num1 + i][num2 + j] != 'W')
                            _b++;
                    }
                }
            }
            _min = min(_min, min(_w, _b));
        }
    }
    printf("%d\n", _min);

    return 0;
}