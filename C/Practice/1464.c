#include <stdio.h>

int main()
{

    const int N = 10;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        int j;
        int duplicate = 0;

        // index i보다 앞쪽에 있는 숫자들 비교
        for (j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                duplicate = 1;
                break;
            }
        }

        // index i보다 뒤쪽에 있는 숫자들과 비교
        if (duplicate == 0)
        {
            for (j = i + 1; j < N; j++)
            {
                if (arr[i] == arr[j])
                {
                    duplicate = 1;
                    break;
                }
            }
        }
        if (duplicate == 0)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}