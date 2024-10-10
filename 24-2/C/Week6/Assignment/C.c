#include <stdio.h>

int main()
{

    unsigned int input[4], output[4] = {
                               0,
                           };
    for (int i = 0; i < 4; i++)
    {
        scanf("%X", &input[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        int pow = 1;
        for (int j = 0; j < 4; j++)
        {
            output[i] += pow * ((input[j] & (0xFF << i * 8)) >> (i * 8));
            pow *= 256;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        printf("%X ", output[i]);
    }

    return 0;
}