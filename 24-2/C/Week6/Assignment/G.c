#include <stdio.h>

int main()
{

    int n, x, cnt = 0, arr[8], num[3], flag;
    scanf("%d %d", &n, &x);

    for (int i = 0; i < 8; i++)
    {
        arr[i] = (n >> (7 - i)) & 1;
    }
    for (int i = 0; i < 3; i++)
    {
        num[i] = (x >> (2 - i)) & 1;
    }

    for (int j = 0; j < 6; j++)
    {
        flag = 1;
        for (int k = 0; k < 3; k++)
        {
            if (arr[j + k] != num[k])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}