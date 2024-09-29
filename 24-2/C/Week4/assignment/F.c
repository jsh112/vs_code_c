// 정수 A와 N을 입력한다.
// A를 N개의 bit만큼 묶어서 한 묶음당 비트
// 1의 개수가 몇 개인지 차례대로 출력한다.

// A(정수, 0 <= A < 2^23)
// N(0 < N < 33)

// 묶음당 비트 1의 개수가 몇 개인지 띄어쓰기로 구분하여 차례대로 출력한다.
// 마지막 묶음은 나머지 비트로 이루어져있다.

// int main()
// {
//     unsigned int a;
//     int n, k = 0;
//     scanf("%u %d", &a, &n);
//     for (int i = 0; i < 32; i += n)
//     {
//         int cnt = 0;
//         for (int j = i; j < (i + n) && j < 32; j++)
//         {
//             if ((a << j) & (0x80 << 24))
//             {
//                 cnt++;
//             }
//         }
//         printf("%d ", cnt);
//     }
//     return 0;
// }

#include <stdio.h>

int main()
{

    unsigned int A;
    int N;

    scanf("%u %d", &A, &N);

    for (int i = 31; i >= 0; i -= N)
    {
        int cnt = 0;
        for (int j = 0; j < N && (i - j) >= 0; j++)
        {
            if (0x01 & (A >> (i - j)))
            {
                cnt++;
            }
        }
        printf("%d ", cnt);
    }

    return 0;
}
