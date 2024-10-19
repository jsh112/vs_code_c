#include <stdio.h>

int my_strlen(char *str)
{
    char *tmp = str;
    while (*tmp)
    {
        tmp++;
    }
    return tmp - str;
}

void func(char *str)
{
    int len = my_strlen(str), cnt = 0;
    int idx[100] = {
        0,
    };
    for (int i = 1; i < len - 1; i++)
    {
        if (str[i - 1] == str[i + 1])
        {
            idx[cnt] = i;
            cnt++;
        }
    }
    for (int j = 0; j < cnt; j++)
    {
        str[idx[j]] = 'x';
    }
    printf("%s", str);
}

int main()
{

    char str[102];
    scanf("%s", str);
    func(str);

    return 0;
}