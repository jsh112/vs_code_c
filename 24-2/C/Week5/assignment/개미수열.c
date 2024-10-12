#include <stdio.h>

int my_strlen(const char *s)
{
    const char *tmp = s;
    while (*tmp)
    {
        tmp++;
    }
    return tmp - s;
}

char *my_strcpy(char *s1, const char *s2)
{
    char *tmp = s1;
    while (*s2)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return tmp;
}

void ant(char *L, char *str, unsigned int n)
{
    int d, cnt;
    for (int i = 2; i <= n; i++)
    {
        d = 0;
        cnt = 0;
        int len = my_strlen(L);
        for (int idx = 0; idx < len; idx++)
        {
            if ((idx < (len - 1)) && (L[idx] == L[idx + 1]))
            {
                cnt++;
            }
            if ((idx < (len - 1)) && (L[idx] != L[idx + 1]))
            {
                str[d++] = L[idx];
                str[d++] = cnt + '0';
                cnt = 0;
            }
        }
        my_strcpy(L, str);
        printf("%s\n", str);
    }
}

int main()
{
    char L[100], str[100];
    unsigned int i;
    int cnt, num;
    scanf("%s %u", L, &i);
    printf("%s\n", L);
    ant(L, str, i - 1);
    return 0;
}