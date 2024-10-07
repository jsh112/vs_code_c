#include <stdio.h>

int main()
{

    char type[100], name[100];
    int i, num[5];
    scanf("%s", type);
    scanf("%s", name);
    scanf("%d", &i);

    char *it = name;
    while (*it != '[')
    {
        it++;
    }
    it++;
    int cnt = 0, k = 1, sum = 0;
    while (*it != ']')
    {
        num[cnt++] = (*it - '0');
        it++;
    }

    for (int j = cnt - 1; j >= 0; j--)
    {
        sum += k * num[j];
        k *= 10;
    }

    if (type[0] == 'i')
    {
        printf("%X", 0x1000 + sizeof(int) * sum * i);
    }

    else if (type[0] == 's')

    {
        printf("%X", 0x1000 + sizeof(short) * sum * i);
    }
    else
    {
        printf("%X", 0x1000 + sizeof(char) * sum * i);
    }

    return 0;
}