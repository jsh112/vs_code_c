#include <stdio.h>

int main()
{
    int a[2][3][4] = {{{1, 2, 3, 4}, {4, 5, 6, 7}, {8, 9, 10, 11}},
                      {{12, 13, 14, 15}, {16, 17, 18, 19}, {20, 21, 22, 23}}};

    printf("address of i : %d\n", (char *)a - (char *)&a);
    printf("address of i + 1 : %d\n", (char *)(a + 1) - (char *)&a);

    printf("address of &i[0] : %d\n", (char *)&a[0] - (char *)&a);
    printf("address of &i[1] : %d\n", (char *)&a[1] - (char *)&a);

    printf("address of &i[0][0] : %d\n", (char *)&a[0][0] - (char *)&a);
    printf("address of &i[0][1] : %d\n", (char *)&a[0][1] - (char *)&a);
    printf("address of &i[1][0] : %d\n", (char *)&a[1][0] - (char *)&a);
    printf("address of &i[1][1] : %d\n", (char *)&a[1][1] - (char *)&a);

    printf("address of i[0] : %d\n", (char *)a[0] - (char *)&a);
    printf("address of i[1] : %d\n", (char *)a[1] - (char *)&a);

    printf("address of i[0][0] : %d\n", (char *)a[0][0] - (int *)&a);
    printf("address of i[0][1] : %d\n", (char *)a[0][1] - (char *)&a);
    printf("address of i[1][0] : %d\n", (char *)a[1][0] - (char *)&a);
    printf("address of i[1][1] : %d\n", (char *)a[1][1] - (char *)&a);

    printf("address of &i[0][2] : %d\n", (char *)&a[0][2] - (char *)&a);
    printf("address of &i[1][2] : %d\n", (char *)&a[1][2] - (char *)&a);

    printf("address of (i[0] + 1) : %d\n", (char *)(a[0] + 1) - (char *)&a);
    printf("address of (i[1] + 1) : %d\n", (char *)(a[1] + 1) - (char *)&a);

    printf("address of *(i + 1) : %d\n", (char *)(*(a + 1)) - (char *)&a);
    printf("address of *(&i[0][0] + 1) : %d\n", (char *)(*(&a[0][0] + 1)) - (char *)&a);

    return 0;
}