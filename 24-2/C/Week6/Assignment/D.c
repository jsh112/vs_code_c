#include <stdio.h>
#define sz 3
#define len 11

int my_strlen(char *s)
{
    char *it = s;
    while (*s)
    {
        s++;
    }
    return s - it;
}

int my_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
        {
            return 0;
        }
        s1++;
        s2++;
    }
    return (!*s1 && !*s2) ? 1 : 0;
}

char *my_strcpy(char *dest, const char *src)
{
    char *tmp = dest;
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return tmp;
}

int check_bingo(char Bingo[sz][sz][len])
{
    int cnt = 0;
    for (int i = 0; i < sz; i++)
    {
        int row_count = 0;
        for (int j = 0; j < sz; j++)
        {
            if (my_strcmp(Bingo[i][j], "."))
            {
                row_count++;
            }
        }
        if (row_count == sz)
        {
            cnt++;
        }
    }

    for (int j = 0; j < sz; j++)
    {
        int col_count = 0;
        for (int i = 0; i < sz; i++)
        {
            if (my_strcmp(Bingo[i][j], "."))
            {
                col_count++;
            }
        }
        if (col_count == sz)
        {
            cnt++;
        }
    }
    int count1 = 0, count2 = 0;
    for (int i = 0; i < sz; i++)
    {
        if (my_strcmp(Bingo[i][i], "."))
        {
            count1++;
        }
        if (my_strcmp(Bingo[i][sz - 1 - i], "."))
        {
            count2++;
        }
    }
    // 이부분이 점수 안나올 수도 있음
    if (count1 == sz)
    {
        cnt++;
    }
    if (count2 == sz)
    {
        cnt++;
    }

    return cnt;
}

int main()
{
    char bingo[sz][sz][len];
    int n;
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            scanf("%s", bingo[i][j]);
        }
    }
    scanf("%d", &n);
    getchar();
    char name[sz * sz][len];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", name[i]);
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                if (my_strcmp(bingo[i][j], name[k]))
                {
                    my_strcpy(bingo[i][j], ".");
                }
            }
        }
    }
    printf("%d", check_bingo(bingo));
    return 0;
}