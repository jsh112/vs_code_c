#include <stdio.h>

int main()
{

    char str_type[10], str_arr[50];
    scanf("%s", str_type);
    getchar();
    scanf("%s", str_arr);

    int sz;
    if (str_type[0] == 'i')
    {
        sz = sizeof(int);
    }
    else if (str_type[0] == 's')
    {
        sz = sizeof(short);
    }
    else
    {
        sz = sizeof(char);
    }
    char *iter = str_arr;
    int array_size;
    while (*iter != '[')
    {
        iter++;
    }
    if (iter != NULL)
    {
        iter++;
        sscanf(iter, "%d", &array_size);
    }
    printf("%d", sz * array_size);

    return 0;
}