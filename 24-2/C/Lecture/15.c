#include <stdio.h>

int main()
{
    int num, shift;
    unsigned char arr[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%X", &num);
        arr[i] = (unsigned char)num;
    }
    getchar();
    scanf("%d", &shift);

    int move_byte = shift / 8;
    int move_bits = shift % 8;

    if (move_byte > 0)
    {
        for (int idx = 10 - 1; idx >= 0; idx--)
        {
            arr[idx] = (idx >= move_byte) ? arr[idx - move_byte] : 0;
        }
    }
    unsigned char carry = 0;
    for (int idx = 0; idx < 9; idx++)
    {
        unsigned int Ncarry = arr[idx] << (8 - move_bits);
        arr[idx] = (arr[idx + 1] >> move_bits) | carry;
        carry = Ncarry;
    }
    arr[9] >>= arr[9] | carry;

    for (int i = 0; i < 10; i++)
    {
        printf("%X ", arr[i]);
    }

    return 0;
}