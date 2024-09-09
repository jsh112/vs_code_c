// 문제 A - 플레이리스트

// 문제 설명
// 음악 플레이리스트에서 한 달마다 5번 이하로 들은 곡은
// 자동으로 삭제하는 기능을 제작하기로 했다.
// 이번 달에 삭제할 곡 번호를 출력하시오.
// 단, 곡 번호는 겹치지 않는다.

// 입력 설명
// N
// A1 A2 A3 ... AN
// B1 B2 B3 ... BN
// N(정수) : 곡의 개수 (0 <= N < 101)
// Ai(정수) : 곡 번호  (0 < Ai < 2^32) (1 <= i < N)
// Bi(정수) : 곡마다 들은 회수 (0 < Bi < 2^32) (1 <= i < N)

// 출력 설명
// 5번 이하로 들은 곡 번호를 띄어쓰기로 구분하여 차례로 출력한다.

// 입력 예시
// 8
// 3 5 7 1 2 6 4 9
// 6 1 3 9 2 5 8 2

// 출력 예시
// 5 7 2 6 9

// ACCEPTED CODE

#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    unsigned int A[N], B[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%u", &A[i]);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%u", &B[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (B[i] <= 5)
        {
            printf("%u ", A[i]);
        }
    }

    return 0;
}