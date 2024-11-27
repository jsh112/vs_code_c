#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct complexNum {
    int real;
    int imaginary;
};

// 이 위로 수정 금지
struct complexNum sum_complex(struct complexNum* c1, struct complexNum* c2) {
    struct complexNum tmp;
    tmp.real = c1->real + c2->real;
    tmp.imaginary = c1->imaginary + c2->imaginary;
    return tmp;
}

struct complexNum sub_complex(struct complexNum* c1, struct complexNum* c2) {
    struct complexNum tmp;
    tmp.real = c1->real - c2->real;
    tmp.imaginary = c1->imaginary - c2->imaginary;
    return tmp;
}
// 이 아래로 수정 금지

int main(int argc, char const* argv[]) {
    struct complexNum com1, com2, sum, sub;
    scanf("%d %d", &com1.real, &com1.imaginary);
    scanf("%d %d", &com2.real, &com2.imaginary);

    sum = sum_complex(&com1, &com2);
    sub = sub_complex(&com1, &com2);

    printf("%d + %di\n", sum.real, sum.imaginary);
    printf("%d + %di\n", sub.real, sub.imaginary);

    return 0;
}