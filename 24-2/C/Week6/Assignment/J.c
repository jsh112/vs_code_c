#include <stdio.h>

int main()
{

    char type[100];
    int size1, size2, I;
    scanf("%s arr[%d][%d];", type, &size1, &size2);
    scanf("%d", &I);

    if (type[0] == 'i')
    {
        printf("%X", 0x1000 + sizeof(int) * size2 * I);
    }
    else if (type[0] == 's')
    {
        printf("%X", 0x1000 + sizeof(short) * size2 * I);
    }
    else
    {
        printf("%X", 0x1000 + sizeof(char) * size2 * I);
    }

    return 0;
}