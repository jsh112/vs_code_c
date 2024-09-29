#include <stdio.h>

// 코드 고치기
// 하나만 들어왔을 때도 생각하기

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