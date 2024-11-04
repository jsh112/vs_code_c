#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char *my_ito16a(char *str, int value) {
    // 이 위로 수정 금지
    char* tmp = str;

    if(value == 0){
        *tmp++ = '0';
    }

    while(value != 0){
        int p = value % 16;
        *tmp = (p > 9) ? ('A' + p - 10) : (p + '0');
        value >>= 4;
        tmp++; 
    }
    *tmp = '\0'; 

    char* end = tmp - 1;
    tmp = str;
    while (tmp < end) {
        char t = *tmp;
        *tmp = *end;
        *end = t;
        tmp++;
        end--;
    }

    return str;
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[]) {
    char S[101] = {0};
    int I;

    scanf("%d", &I);

    char *p = my_ito16a(S, I);
    if (p == S)
        printf("%s", p);
    else
        printf("This is wrong!!!\n");

    return 0;
}