#include <stdio.h>

// T N M L A B C
// arr[A][B][C]

int main()
{

    char t[30];
    int m, n, k, a, b, c;
    scanf("%s", t);
    scanf("%d %d %d %d %d %d", &m, &n, &k, &a, &b, &c);

    if (t[0] == 'c')
    {
        printf("%X", 0x1000 + sizeof(char) * ((b * c) * m + c * n + k));
    }
    else if (t[0] == 's')
    {
        printf("%X", 0x1000 + sizeof(short) * ((b * c) * m + c * n + k));
    }
    else
    {
        printf("%X", 0x1000 + sizeof(int) * ((b * c) * m + c * n + k));
    }

    // char t[30];
    // gets(t);

    // if (t[0] == 'c')
    // {
    //     printf("%X", 0x1000 + sizeof(char) * (((t[7] - '0') * (t[9] - '0')) * (t[11] - '0') + (t[9] - '0') * (t[13] - '0') + (t[15] - '0')));
    // }
    // else if (t[0] == 's')
    // {
    //     printf("%X", 0x1000 + sizeof(short) * (((t[8] - '0') * (t[10] - '0')) * (t[12] - '0') + (t[10] - '0') * (t[14] - '0') + (t[16] - '0')));
    // }
    // else
    // {
    //     printf("%X", 0x1000 + sizeof(int) * (((t[6] - '0') * (t[8] - '0')) * (t[10] - '0') + (t[8] - '0') * (t[12] - '0') + (t[8] - '0')));
    // }

    return 0;
}