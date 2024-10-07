#include <stdio.h>

int my_strcmp(const char *s1, const char *s2)
{
    // is same to (*s1 != '\0 && *s2 != '\0')
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
        {
            return 0;
        }
        s1++;
        s2++;
    }
    return (*s1 == '\0' && *s2 == '\0') ? 1 : 0;
}

char *my_strcpy(char *dest, const char *src)
{
    char *_d = dest;
    if (*src)
    {
        *dest = *src;
        dest++;
    }
    *dest = '\0';
    return _d;
}

int main()
{

    char bingo[3][3][11];
    char called_names[10][11];
    int num;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%s", bingo[i][j]);
        }
    }
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%s", called_names[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < num; k++)
            {
                if (my_strcmp(bingo[i][j], called_names[k]))
                {
                    my_strcpy(bingo[i][j], ".");
                }
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%s ", bingo[i][j]);
        }
        printf("\n");
    }

    return 0;
}