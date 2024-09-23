#include <stdio.h>

void print_and(int _a[], int _b[])
{
    for (int i = 0; i < 32; i++)
    {
        if ((_a[i] == 1) && (_b[i] == 1))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
}

void print_or(int *_a, int *_b)
{
    for (int i = 0; i < 32; i++)
    {
        if ((_a[i] == 1) || (_b[i] == 1))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
}
void print_xor(int *_a, int *_b)
{
    for (int i = 0; i < 32; i++)
    {
        if (_a[i] == _b[i])
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
    }
    printf("\n");
}

void determin_logic(int *_a, int *_b)
{
    int logic_a = 0, logic_b = 0;
    for (int i = 0; i < 32; i++)
    {
        if (_a[i] == 1)
        {
            logic_a = 1;
        }
        if (_b[i] == 1)
        {
            logic_b = 1;
        }
    }
    printf("%d\n", logic_a && logic_b);
    printf("%d\n", logic_a || logic_b);
}

int main()
{

    char a[33], b[33];
    int len1 = 0, len2 = 0, _a[32], _b[32];
    gets(a);
    gets(b);

    while (a[len1] != '\0')
    {
        _a[len1] = a[len1] - '0';
        len1++;
    }
    while (b[len2] != '\0')
    {
        _b[len2] = b[len2] - '0';
        len2++;
    }

    for (int i = len1; i < 32; i++)
    {
        _a[i] = 0;
    }

    for (int i = len2; i < 32; i++)
    {
        _b[i] = 0;
    }
    print_and(_a, _b);
    print_or(_a, _b);
    print_xor(_a, _b);
    determin_logic(_a, _b);

    return 0;
}