#include <stdio.h>

int main()
{

    char s[105], w[16];
    gets(s);
    gets(w);

    char *s_iter = s;
    char *w_iter = w;

    while (*s_iter)
    {
        char *tmp_s = s_iter;
        char *tmp_w = w_iter;
        while (*tmp_s && *tmp_w && (*tmp_s == *tmp_w))
        {
            tmp_s++;
            tmp_w++;
        }

        if (*tmp_w == '\0')
        {
            while (s_iter < tmp_s)
            {
                *s_iter = '#';
                s_iter++;
            }
            break;
        }

        s_iter++;
    }
    printf("%s", s);

    return 0;
}