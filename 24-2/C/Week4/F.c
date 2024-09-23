#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    // 1 -> 0x01로 출력하려면
    // i가 7부터 0까지로 가면 된다.
    for (int i = 0; i < 8; i++)
    {
        printf("%d", (n >> i) & 0x01);
    }
    return 0;
}