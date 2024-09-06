#include <stdio.h>

void InsertSort(int arr[], int len);

int main()
{

    int arr[10] = {9, 17, 5, 6, 124, 112, 1, 3, 87, 55};
    int len = sizeof(arr) / sizeof(int);
    int tmp, j;

    // insert sort
    InsertSort(arr, len);

    // print the array
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

// key 값을 기억해두고 j가 움직이면서 값을 서로 바꾼다
// 8 5 6 2 4의 경우

// 5가 key, j는 (i - 1)을 가리킨다
// 만약 a[j] > key이면 a[j+1] = a[j]로 한다.
// 그리고 j는 1씩 작아진다.
// 그럼 8 8 6 2 4에 j는 -1이므로 for loop이 종료된다
// 5 8 6 2 4를 만들어야 하므로 a[j + 1] = key가 된다
void InsertSort(int arr[], int len)
{
    int i, j, key;
    for (i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}