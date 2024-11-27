#include <stdio.h>

struct s {
    int a;
    float f;
} var1, var2;

int main() {
    /* var1.a = 10;
    var1.f = 100.23;

    var2 = var1;
    printf("%d %.1f", var2.a, var2.f); */

    struct Test {
        char a, b, c, d;
        int i;
        char str[100];
    } varA;

    varA.a = 65;
    varA.b = 66;
    varA.c = 67;
    varA.d = 0;

    // 주소 출력
    printf("%d\n", varA);
    printf("%s\n", varA);
    // ABC '\0' -> ABC
    printf("%s\n", &varA);

    return 0;
}