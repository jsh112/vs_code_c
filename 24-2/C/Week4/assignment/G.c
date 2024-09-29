// 입력한 정수 N개 중 연속해서 가장 많이 입력한 정수를 출력하는 프로그램을 작성하시오.

// N (정수, 처리할 정수의 개수들)
// A1, A2, ... , AN (정수, 처리할 정수들)

// 0 < N < 2^32
// 0 <= Ai < 2^32 (1 <= i <= N)

// 연속해서 가장 많이 입력한 정수를 출력한다.
// 만약 동일한 횟수로 입력된 수가 있다면, 먼저 입력한 수를 출력한다.

// pseudo code

// initial count
//

#include <stdio.h>

int main()
{

    unsigned int n, k;
    scanf("%u", &n);
    unsigned int arr[n];
    int cnt = 1;

    int print = 0, max = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%u", &arr[i]);
        if (i != 0)
        {
            if (arr[i - 1] == arr[i])
            {
                cnt++;
                if (max < cnt)
                {
                    print = arr[i];
                    max = cnt;
                }
            }
            else
            {
                if (max < cnt)
                {
                    max = cnt;
                }
                cnt = 1;
            }
        }
        else if (i == 0)
        {
            print = arr[i];
        }
    }
    printf("%d", print);

    return 0;
}
