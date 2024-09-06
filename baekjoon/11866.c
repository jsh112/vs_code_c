#include <stdio.h>

int main()
{

    int n, k;
    scanf("%d %d", &n, &k);
    int josephus[n], cnt = n - 1;
    for (int i = 1; i <= n; i++)
    {
        josephus[i] = i;
    }

    printf("<");
    printf("%d, ", k);
    int tmp = k;
    josephus[k] = 0;
    while (cnt != 0)
    {
        if (josephus[(k + tmp) % n] != 0)
        {
            printf("%d, ", josephus[(k + tmp) % n]);
            josephus[(k + tmp) % n] = 0;
            cnt--;
            k = (k + tmp) % n;
        }
        else
        {
            k = (k + tmp) % n;
            if (k == 0)
            {
                k = 1;
            }
        }
    }
    printf(">");

    return 0;
}