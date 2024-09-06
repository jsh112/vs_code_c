#include <stdio.h>

int main()
{
    int arr[10] = {9, 17, 5, 6, 124, 112, 1, 3, 87, 55};
    int len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}