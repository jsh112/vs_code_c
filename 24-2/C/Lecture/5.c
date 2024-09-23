#include <stdio.h>

int main()
{

    int i[3][4] = {100, 200, 300, 400, 500};

    // printf("i = %p\n", (void *)i);
    // printf("i+1 = %p\n", (void *)(i + 1));

    // printf("i[0] = %p\n", (void *)i[0]);
    // printf("i[1] = %p\n", (void *)i[1]);
    // printf("i[2] = %p\n", (void *)i[2]);

    // printf("i[0]+1 = %p\n", (void *)(i[0] + 1));
    // printf("i[1]+1 = %p\n", (void *)(i[1] + 1));
    // printf("i[2]+1 = %p\n", (void *)(i[2] + 1));

    // printf("&i[0] = %p\n", (void *)&i[0]);
    // printf("&i[1] = %p\n", (void *)&i[1]);
    // printf("&i[2] = %p\n", (void *)&i[2]);

    // printf("&i[0] + 1 = %p\n", (void *)(&i[0] + 1));
    // printf("&i[1] + 1 = %p\n", (void *)(&i[1] + 1));
    // printf("&i[2] + 1 = %p\n", (void *)(&i[2] + 1));

    // printf("&i[0][0] = %p\n", (void *)&i[0][0]);
    // printf("&i[1][0] = %p\n", (void *)&i[1][0]);

    // printf("&i[0][0] + 1 = %p\n", (void *)(&i[0][0] + 1));
    // printf("&i[1][0] + 1 = %p\n", (void *)(&i[1][0] + 1));

    char *basic = (char *)i;

    printf("i = %ld\n", (char *)i - basic);
    printf("i+1 = %ld\n\n", (char *)(i + 1) - basic);

    printf("&i = %ld\n", (char *)&i - basic);
    printf("i+1 = %ld\n\n", (char *)(&i + 1) - basic);

    printf("i[0] = %ld\n", (char *)i[0] - basic);
    printf("i[1] = %ld\n", (char *)i[1] - basic);
    printf("i[2] = %ld\n\n", (char *)i[2] - basic);

    printf("i[0]+1 = %ld\n", (char *)(i[0] + 1) - basic);
    printf("i[1]+1 = %ld\n", (char *)(i[1] + 1) - basic);
    printf("i[2]+1 = %ld\n\n", (char *)(i[2] + 1) - basic);

    printf("&i[0] = %ld\n", (char *)&i[0] - basic);
    printf("&i[1] = %ld\n", (char *)&i[1] - basic);
    printf("&i[2] = %ld\n\n", (char *)&i[2] - basic);

    printf("&i[0] + 1 = %ld\n", (char *)(&i[0] + 1) - basic);
    printf("&i[1] + 1 = %ld\n", (char *)(&i[1] + 1) - basic);
    printf("&i[2] + 1 = %ld\n\n", (char *)(&i[2] + 1) - basic);

    printf("&i[0][0] = %ld\n", (char *)&i[0][0] - basic);
    printf("&i[1][0] = %ld\n\n", (char *)&i[1][0] - basic);

    printf("&i[0][0] + 1 = %ld\n", (char *)(&i[0][0] + 1) - basic);
    printf("&i[1][0] + 1 = %ld\n", (char *)(&i[1][0] + 1) - basic);
    return 0;
}