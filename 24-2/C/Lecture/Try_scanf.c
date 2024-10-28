#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    int sz1, sz2, sz3;
    scanf("%s %[^[][%d][%d][%d]", str1, str2, &sz1, &sz2, &sz3);
    printf("%s %s %d %d %d", str1, str2, sz1, sz2, sz3);
    return 0;
}