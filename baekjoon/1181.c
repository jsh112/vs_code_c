#include <stdio.h>

size_t my_strlen(const char *str);
int my_strcmp(const char *str1, const char *str2);
char *my_strcpy(char *dest, const char *src);
void swap(char *str1, char *str2);

int main()
{

    return 0;
}

size_t my_strlen(const char *str)
{
    int cnt = 0;
    while (str[cnt] != '\0')
    {
        cnt++;
    }
    return cnt;
}
int my_strcmp(const char *str1, const char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] < str2[i])
        {
            return 1; // str1 comes before str2
        }
        else if (str1[i] > str2[i])
        {
            return -1; // str1 comes after str2
        }
        i++;
    }
    // If both strings are the same so far, check lengths
    if (str1[i] == '\0' && str2[i] == '\0')
    {
        return 0; // Strings are equal
    }
    else if (str1[i] == '\0')
    {
        return 1; // str1 is shorter, hence comes before
    }
    else
    {
        return -1; // str1 is longer, hence comes after
    }
}

void swap(char *str1, char *str2)
{
    for (int i = 0; i < 50; i++)
    {
        char tmp = str1[i];
        str1[i] = str2[i];
        str1[i] = tmp;
    }
}

char *my_strcpy(char *dest, const char *src)
{
    for (int i = 0; i < my_strlen(src); i++)
    {
        dest[i] = src[i];
    }
    return dest;
}