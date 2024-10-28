#include <stdio.h>

int main()
{

    const int sz = 10;
    int N;
    unsigned int arr[sz];
    for (int i = 0; i < sz; i++)
    {
        scanf("%X", &arr[i]);
    }
    scanf("%d", &N);

    if (N > 0)
    {
        for (int i = 0; i < 80; i++)
        {
            // shift left
            int t = i + N;

            int src_idx = t / 8;
            int src_mask = (0x01 << (t % 8));
            int dest_idx = i / 8;
            int dest_mask = (0x01 << (i % 8));
            int b = 0;
            if (t < 80)
            {
                b = arr[src_idx] & src_mask;
            }
            if (b == 1)
            {
                arr[dest_idx] |= dest_mask;
            }
            else
            {
                arr[dest_idx] &= ~dest_mask;
            }
        }
    }
    else
    {
        for (int i = 0; i < 80; i++)
        {
            // shift right
            int t = i + N;

            int src_idx = t / 8;
            int src_mask = (0x01 << (t % 8));
            int dest_idx = i / 8;
            int dest_mask = (0x01 << (i % 8));
            int b = 0;
            if (t >= 0)
            {
                b = arr[src_idx] & src_mask;
            }
            if (b == 1)
            {
                arr[dest_idx] |= dest_mask;
            }
            else
            {
                arr[dest_idx] &= ~dest_mask;
            }
        }
    }

    for (int i = 0; i < sz; i++)
    {
        printf("%X ", arr[i]);
    }

    return 0;
}