#include <stdio.h>

// 비트연산(LSB, MSB 파악)
// 쉬프트 개념, 간단하게 표현하기
// N이 32까지이므로 배열 크기도 항상 생각하고
// iterator 등을 활용해서 빈 공간에는 접근하지 않기(k 사용 아이디어 괜찮았음)
// b 배열 필요없음

int main()
{
    unsigned int a;
    int n, k = 0, b[32];
    scanf("%u %d", &a, &n);
    for (int i = 0; i < 32; i += n)
    {
        int cnt = 0;
        for (int j = i; j < (i + n) && j < 32; j++)
        {
            if ((a << j) & (0x80 << 24))
            {
                cnt++;
            }
        }
        // b[k] = cnt;
        // k++;
        printf("%d ", cnt);
    }
    // 3 3 2 0 E 6 6 3
    // for (int i = 0; i < k; i++)
    // {
    //     printf("%d ", b[i]);
    // }
    return 0;
}