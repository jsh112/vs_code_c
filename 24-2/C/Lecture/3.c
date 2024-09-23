#include <stdio.h>

char a[5] = {
    'a',
};

int main()
{
    int b[5] = {1};
    for (int i = 0; i < 5; i++)
    {
        printf("%d %d\n", a[i], b[i]);
    }

    // char a[12] = "I am a boy";
    // printf("%p\n", a);
    // printf("%p\n", &a);
    // printf("%p\n", &a[0]);

    // for (int i = 0; i < 12; i++)
    // {
    //     if (a[i] == ' ')
    //     {
    //         printf("!!! ");
    //     }
    //     else if (a[i] == 0)
    //     {
    //         printf("??? ");
    //     }
    //     else
    //     {
    //         printf("%c ", a[i]);
    //     }
    // }

    return 0;
}