#include <stdio.h>

int main()
{

    int num;
    unsigned char arr[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%X", &num);
        arr[i] = (unsigned char)num;
    }
    int shift;
    getchar();
    scanf("%d", &shift);

    int quotient = shift / 8;
    int mode = shift % 8;
    int idx = 0;
    while (idx + quotient < 10)
        idx++;

    // for (; idx - quotient >= 0; idx--)
    // {
    //     arr[idx] = arr[idx - quotient];
    // }
    // for (; idx >= 0; idx--)
    // {
    //     arr[idx] = 0;
    // }

    for (; idx >= 0; idx--)
    {
        arr[idx] = (idx - quotient >= 0) ? arr[idx - quotient] : 0;
    }

    for (int i = 9; i >= 1; i--)
    {
        arr[i] >>= mode;
        arr[i] |= (arr[i - 1] & ((1 << mode) - 1)) << (8 - mode);
    }
    arr[0] = arr[0] >> mode;
    for (int j = 0; j < 10; j++)
    {
        printf("%X ", arr[j]);
    }
    return 0;
}