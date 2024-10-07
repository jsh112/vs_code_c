#include <stdio.h>

int main()
{
    int a, d, sum = 0, pow = 1, arr[8] = {0}, cnt = 0;
    scanf("%X", &a);
    scanf("%d", &d);

    // 비트를 arr 배열에 저장
    for (int i = d - 1; i < 8; i += d)
    {
        int bit = (a >> i) & 0x01;
        arr[cnt++] = bit;
        sum += bit * pow;
        pow *= 2;
    }

    // 마지막 0을 제거
    while (cnt > 0 && arr[cnt - 1] == 0)
    {
        cnt--;
    }

    // 비트 출력
    if (cnt == 0)
    {
        printf("0"); // 모든 비트가 0인 경우 "0" 출력
    }
    else
    {
        for (int j = cnt - 1; j >= 0; j--)
        {
            printf("%d", arr[j]);
        }
    }

    // 합계 출력
    printf("\n%d", sum);

    return 0;
}
