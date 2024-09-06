#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    unsigned int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%u", &a[i]);
    }

    // n is 3 -> n[1]
    // n is 4 -> n[2]
    printf("%u\n", a[n / 2]);

    return 0;
}