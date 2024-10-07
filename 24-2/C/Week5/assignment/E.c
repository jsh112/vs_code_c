#include <stdio.h>

int main()
{

    unsigned int n, cnt[26] = {
                        0,
                    };
    scanf("%u", &n);
    getchar();
    char c;
    for (unsigned int i = 0; i < n; i++)
    {
        scanf("%c", &c);
        cnt[c - 'a']++;
        getchar();
        }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] != 0)
        {
            printf("%c:%d\n", i + 'a', cnt[i]);
        }
    }

    return 0;
}