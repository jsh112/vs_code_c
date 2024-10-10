#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned int num;
    scanf("%X", &num);
    unsigned char *p = (unsigned char *)&num;
    unsigned char tmp;

    tmp = *(p + 1);
    *(p + 1) = *p;
    *p = tmp;

    tmp = *(p + 2);
    *(p + 2) = *(p + 3);
    *(p + 3) = tmp;

    printf("%X", num);

    return 0;
}