#include <stdio.h>

int main()
{

    char a[11][11];

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            // 문자를 하나씩 입력받음
            scanf(" %c", &a[i][j]); // 앞의 공백은 이전 입력에서 남아있는 공백이나 줄바꿈을 무시
        }
    }

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (a[i][j] == '@')
            {

                i = (i >= 5) ? (i - 5) : (5 - i);
                j = (j >= 5) ? (j - 5) : (5 - j);
                int p = (i > j) ? i : j;
                printf("%d\n", 5 - p);
                return 0;
            }
        }
    }

    return 0;
}