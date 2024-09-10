#include <stdio.h>

int main()
{
    unsigned int n;
    scanf("%u", &n);
    int cnt = 0;
    for (int i = 0; i < 32; i++)
    {
        if (n & 0x01)
        {
            cnt++;
        }
        n = n >> 1;
    }
    printf("%d\n", cnt);
    return 0;
}