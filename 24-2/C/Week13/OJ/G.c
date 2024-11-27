#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
struct userInfo {
    char name[100];
    unsigned int age;
};
// 이 아래로 수정 금지

int main(void) {
    struct userInfo u = {"", 0};

    scanf("%s %u", u.name, &u.age);
    printf("Hello, my name is %s. And I'm %u years old.", u.name, u.age);
}
