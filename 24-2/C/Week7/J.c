#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int arr[n], I[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &I[i]);
    }

    unsigned int sum = 0, factor = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += I[i] * factor;
        factor *= arr[i];
    }
    printf("%X", 0x1000 + sum);

    return 0;
}