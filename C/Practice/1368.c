#include <stdio.h>
#include <string.h>

int checkpalin(char ch[]);

int main()
{

    char ch[20];
    scanf("%s", ch);

    printf("%d", checkpalin(ch));

    return 0;
}

int checkpalin(char ch[])
{
    int len = strlen(ch);
    for (int i = 0; i <= (len - 1) / 2; i++)
    {
        if (ch[i] != ch[len - 1 - i])
        {
            return 0;
        }
    }
    return 1;
}