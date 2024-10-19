#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int s[n], idx[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &idx[i]);
    }

    int factor = 1, dim = n - 1;
    unsigned int sum = idx[dim];
    while (dim != 0)
    {
        factor *= s[dim];
        dim--;
        sum += factor * idx[dim];
    }

    printf("%X", 0x1000 + sum);
    return 0;
}