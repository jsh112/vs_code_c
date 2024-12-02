#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
unsigned int calc(unsigned int a, unsigned int b, unsigned int (*add)(unsigned int, unsigned int)) {
    return add(a, b);
}
// 이 아래로 수정 금지

unsigned int add(unsigned int a, unsigned int b) {
    return a + b;
}

int main(int argc, char const *argv[]) {
    unsigned int a, b;
    scanf("%u %u", &a, &b);

    printf("%u", calc(a, b, add));

    return 0;
}