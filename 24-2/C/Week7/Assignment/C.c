#include <stdio.h>
#define SZ 10
int main()
{

    int num, N;
    unsigned char arr[SZ];
    for (int i = 0; i < SZ; i++)
    {
        scanf("%X", &num);
        arr[i] = (unsigned char)num;
    }
    getchar();
    scanf("%d", &N);

    int ByteMove = N / 8;
    int bitMove = N % 8;

    for (int idx = SZ - 1; idx - ByteMove >= 0; idx--)
    {
        arr[idx] = arr[idx - ByteMove];
    }
    for (int idx = SZ - 1; idx > 0; idx--)
    {
        arr[idx] >>= bitMove;
        arr[idx] |= (arr[idx - 1] << (8 - bitMove));
    }
    arr[0] >>= bitMove;

    for (int i = 0; i < SZ; i++)
    {
        printf("%X ", arr[i]);
    }
    return 0;
}