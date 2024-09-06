#include <stdio.h>

const int N = 101;
int _len(char *ch)
{
    int len = 0;
    while (ch[len] != '\0')
    {
        len++;
    }
    return len;
}

int main()
{

    char S[N], W[N];
    gets(S);
    gets(W);

    int len_s = _len(S);
    int len_w = _len(W);

    if (len_s < len_w)
    {
        printf("%s?", W);
        return 0;
    }

    int flag = 0;

    for (int i = 0; i <= len_s - len_w; i++)
    {
        int j;
        for (j = 0; j < len_w; j++)
        {
            if (S[i + j] != W[j])
            {
                break;
            }
        }
        if (j == len_w)
        {
            flag = 1;
        }
    }
    if (flag)
    {
        printf("%s!\n", W);
    }
    else
    {
        printf("%s?\n", W);
    }

    return 0;
}