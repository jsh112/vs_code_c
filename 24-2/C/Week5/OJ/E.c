#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int a[n], cnt, tmp;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (i == 0)
        {
            tmp = a[i];
            cnt = 1;
        }
        else
        {
            if (a[i - 1] != a[i])
            {
                printf("%d%d", tmp, cnt);
                tmp = a[i];
                cnt = 1;
            }
            else if (cnt == 9)
            {
                printf("%d%d", tmp, cnt);
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
    }
    printf("%d%d", tmp, cnt);

    return 0;
}