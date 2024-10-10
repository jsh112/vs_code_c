#include <stdio.h>
#include <string.h>

size_t my_strlen(const char *s)
{
    const char *start = s;
    while (*s)
    {
        s++;
    }
    return s - start;
}

char *my_strcpy(char *dest, const char *src)
{
    char *o_dest = dest;
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return o_dest;
}

// strcat
// char *my_strcat(char *dest, const char *src)
// {
//     char *r_dest = dest;
//     while (*dest)
//     {
//         dest++;
//     };

//     // Copy src to the end of dest
//     while (*src)
//     {
//         *dest = *src;
//         dest++;
//         src++;
//     }

//     // Null-terminate the result
//     *dest = '\0';

//     return r_dest;
// }
char *my_strcat(char *dest, const char *src)
{
    // Uses strcpy to copy src to the end of dest.
    my_strcpy(dest + my_strlen(dest), src);

    // Returns the original pointer to dest.
    return dest;
}

// strcmp
// str1 < str2 인 경우 음수 반환
// str1 > str2 인 경우 양수 반환
// str1 == str2인 경우   0 반환
// str1 = "abc", str2 = "abcd" -> str1 < str2 -> -1반환
// str1 = "ABC", str2 = "ab" -> str1 < str

int my_strcmp(const char *_Str1, const char *_Str2)
{
    while (*_Str1 == *_Str2)
    {
        if (!*_Str1 && !*_Str2)
        {
            return 0;
        }
        _Str1++;
        _Str2++;
    }
    return (*(unsigned char *)_Str1 > *(unsigned char *)_Str2) ? 1 : -1;
}

// memcpy

int main()
{
    // char *cp3 = {1,2}; 불가능
    // 주소를 담아야 하는데 여러개를 초기화

    // char *cp6 = 'a'; 가능(컴파일러가 막지는 않음)하지만 의도치 않은 동작일 확률이 높음
    // char *cp7 = 100; 가능(컴파일러가 막지는 않음)하지만 의도치 않은 동작일 확률이 높음

    // 이차원 배열일 경우 함수 인자에서 char a[][2] 또는 char** a?

    const char *a = "";
    const char *b = "a";
    printf("%d\n", my_strcmp(a, b));
    printf("%d\n", strcmp(a, b));
    return 0;
}