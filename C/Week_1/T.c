#include <stdio.h>

void swap(int *a, int *b);
void swap_us(unsigned int *a, unsigned int *b);

int main()
{
    int N, k = 0;
    scanf("%d", &N);

    unsigned int arr[N];
    unsigned int a1[N];
    int a2[N];

    for (int i = 0; i < N; i++)
    {
        a1[i] = 0;
        a2[i] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%u", &arr[i]);
        int duplicated = 0, j;

        // i index보다 앞쪽에 있는 숫자들 비교
        for (j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                if (duplicated)
                {
                    continue;
                }
                duplicated = 1;
                for (int x = 0; x < i; x++)
                {
                    if (a1[x] == arr[j])
                    {
                        a2[x]++;
                        break;
                    }
                }
            }
        }
        if (duplicated == 0)
        {
            a1[k] = arr[i];
            a2[k]++;
            k++;
        }
    }

    // sort the a1 array and a2 array
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (a1[j] > a1[j + 1] && (a2[j + 1] != 0))
            {
                swap_us(&a1[j], &a1[j + 1]);
                swap(&a2[j], &a2[j + 1]);
            }
        }
    }

    int max = a2[0];
    int c = a1[0];
    for (int i = 0; i < N; i++)
    {
        if (a2[i] == 0)
        {
            break;
        }
        else
        {
            if (max < a2[i])
            {
                max = a2[i];
                c = a1[i];
            }
        }
    }
    printf("%d\n", c);

    return 0;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_us(unsigned int *a, unsigned int *b)
{
    unsigned int tmp = *a;
    *a = *b;
    *b = tmp;
}