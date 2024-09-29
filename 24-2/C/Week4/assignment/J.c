// 압축되어 있는 수열이 주어질 때, 이 수열을 압축 해제하여 출력하는 프로그램을 작성하시오.
// 압축을 해제하는 방법은 다음과 같다.

// 각 숫자 a와 그 숫자의 반복 횟수 b가 쌍으로 주어진다.
// 예를 들어, 14는 숫자 1이 4번 연속으로 나타난다는 의미이다.
// 1911은 숫자 1이 9번 연속으로 나타나고, 숫자 1이 1번 연속으로 나타나므로,
// 숫자 1이 총 10번 연속으로 나타난다는 의미이다.

#include <stdio.h>

int main()
{

    static unsigned int N;
    scanf("%u", &N);
    int A[N];
    for (unsigned int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    int cnt = 0;
    // 두개씩 조사할거니까 (j + 1) < N, j < N - 1로 설정
    for (unsigned int j = 0; (j + 1) < N; j += 2)
    {
        for (int iter = 0; iter < A[j + 1]; iter++)
        {
            printf("%d", A[j]);
        }
    }

    return 0;
}