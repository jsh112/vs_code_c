#include <stdio.h>
#define SZ 10

void shift(unsigned char *arr, int move)
{
    int idx;
    for (idx = 0; idx < SZ - 1; idx++)
    {
        arr[idx] = (arr[idx] << move) & 0xFF;
        arr[idx] |= ((arr[idx + 1] >> (8 - move)) & ((1 << move) - 1));
    }
    arr[9] = (arr[9] << move) & 0xFF;
}

int main()
{

    int a, n, byte;
    unsigned char arr[SZ], std = 0xFF;
    for (int i = 0; i < SZ; i++)
    {
        scanf("%X", &byte);
        arr[i] = (unsigned char)byte;
    }
    scanf("%d", &n);
    // 79 = 8 * 9 + 7
    int duration = n / 8;
    int move = n % 8;

    if (duration == 0)
    {
        // 0011 0011 / 1100 0011 , 2 bit shift
        // 1100 111'1' / (11)0000 110'0'
        // arr[0] = (arr[0] << move) & 0xFF + (arr[1] & (0xF0 << move)) & (0xF << move);
        shift(arr, move);
    }
    else
    {
        int j;
        for (j = 0; j + duration < 10; j++)
        {
            arr[j] = arr[j + duration];
        }
        int tmp = j;
        for (; j < 10; j++)
        {
            arr[j] = 0;
        }
        shift(arr, move);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%X ", arr[i]);
    }

    return 0;
}