#include <stdio.h>

char L[100], str[100];

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
    for (unsigned int i = 2; i <= n; i++)
    {
        int idx_str = 0;
        int len = my_strlen(L);
        for (int L_idx = 0; L_idx < len; L_idx++)
        {
            char current_char = L[L_idx];
            int count = 1;

            while (L_idx + 1 < len && L[L_idx + 1] == current_char)
            {
                count++;
                L_idx++;
            }

            // str에 결과 추가
            str[idx_str++] = current_char;
            str[idx_str++] = count + '0';
        }
        str[idx_str] = '\0';
        my_strcpy(L, str);
        printf("%s\n", L);
    }
}

int main()
{
    unsigned int i;
    int cnt, num;
    scanf("%s %u", L, &i);
    printf("%s\n", L);
    ant(L, str, i);
    return 0;
}