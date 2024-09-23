#include <stdio.h>

int main()
{
    unsigned int n, m;
    scanf("%u", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%u", &m);
    int b[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (b[i] == a[j])
            {
                cnt++;
            }
        }
        printf("%d ", cnt);
    }

    return 0;
}