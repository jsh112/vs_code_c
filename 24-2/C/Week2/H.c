#include <stdio.h>

int main()
{

    unsigned int n;
    scanf("%x", &n);

    for (int i = 0; i < 4; i++)
    {
        printf("%X ", n & 0xFF);
        n = n >> 8;
    }

    return 0;
}