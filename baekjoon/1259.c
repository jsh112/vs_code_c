// #include <stdio.h>

// int main()
// {
//     int n;
//     while (1)
//     {
//         int arr[5];
//         int x, flag = 1;
//         scanf("%d", &n);
//         if (n == 0)
//             break;
//         for (int i = 0; i < 5; i++)
//         {
//             arr[i] = n % 10;
//             n /= 10;
//             if (n == 0)
//             {
//                 x = i;
//                 break;
//             }
//         }
//         for (int j = 0; j <= (x / 2); j++)
//         {
//             if (arr[j] != arr[x - j])
//             {
//                 printf("no\n");
//                 flag = 0;
//                 break;
//             }
//             else
//             {
//                 continue;
//             }
//         }
//         if (flag == 1)
//         {
//             printf("yes\n");
//         }
//     }

//     return 0;
// }

#include <stdio.h>

int main()
{

    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }

        int ori = n, reversed = 0;

        while (n > 0)
        {
            reversed = reversed * 10 + (n % 10);
            n /= 10;
        }
        if (reversed == ori)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }

    return 0;
}