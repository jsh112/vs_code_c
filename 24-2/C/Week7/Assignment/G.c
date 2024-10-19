#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지

int my_strlen(const char *s)
{
    const char *tmp = s;
    while (*tmp)
    {
        tmp++;
    }
    return tmp - s;
}

unsigned int strSimilarity(char *s1, char *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    unsigned int cnt = 0;
    unsigned int len = (len1 < len2) ? len1 : len2;
    unsigned int max = (len1 > len2) ? len1 : len2;

    unsigned tmp_len = len;
    while (len != 0)
    {
        if (*s1 == *s2)
        {
            cnt++;
        }
        s1++;
        s2++;
        len--;
    }
    return ((cnt * 100) / max);
}
// 이 아래로 수정 금지

int main(int argc, char const *argv[])
{
    char str1[101] = {0}, str2[101] = {0};
    scanf("%[^\n]\n", str1);
    scanf("%[^\n]", str2);

    unsigned int similarity = strSimilarity(str1, str2);
    printf("%u%%", similarity);

    return 0;
}