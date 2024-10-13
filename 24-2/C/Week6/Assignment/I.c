#include <stdio.h>

int main()
{

    char type[100], name[100];
    int size, I;
    scanf("%s %s [%d];", type, name, &size);
    scanf("%d", &I);

    // hi
    if (type[0] == 'i')
    {
        printf("%X", 0x1000 + sizeof(int) * size * I);
    }
    else if (type[0] == 's')
    {
        printf("%X", 0x1000 + sizeof(short) * size * I);
    }
    else
    {
        printf("%X", 0x1000 + sizeof(char) * size * I);
    }

    return 0;
}