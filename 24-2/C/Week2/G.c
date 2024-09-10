#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    unsigned char a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // 170 - 128 = 42 -> 42 - 32 = 10
    // 1010 1010 -> 10 + 160
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (a[i] & 0x80)
            {
                printf("-");
            }
            else
            {
                printf("_");
            }
            a[i] = a[i] << 1;
        }
    }

    return 0;
}