#include <stdio.h>

struct score {
    char name[20];
} a, *b;

char *p = a.name;
b = &a;

int main() {
    p[1] = 'A';
    a.name[1] = 'B';
    b->name[1] = 'C';

    // 구조체의 . , -> 연산자 뒤에는 반드시 구조체 필드 이름이 와야한다.
    // expected field name

    // a.p[1] = 'D'
    // a.(*(name + 2)) = 'F';
    // a.(name + 2)
}