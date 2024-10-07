#include <stdio.h>

int main()
{

    unsigned int n;
    scanf("%X", &n);

    unsigned char *it1 = (unsigned char *)&n, tmp;

    tmp = *(it1 + 2);
    *(it1 + 2) = *(it1 + 3);
    *(it1 + 3) = tmp;

    tmp = *it1;
    *it1 = *(it1 + 1);
    *(it1 + 1) = tmp;

    printf("%X", n);

    return 0;
}