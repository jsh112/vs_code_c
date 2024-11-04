#include <stdio.h>

// *arr -> *&arr[0] = arr[0]
// arr[0] + I = &arr[0][0] + I

int main() {
    char type[10], c;
    int idx = 0, num = 0, I;
    unsigned int factor = 1, sum = 0;

    scanf("%s", type);

    while ((c = getchar()) != ';') {
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        } else if (c == ']') {
            if(idx > 1)
                factor *= num;
            idx++;
            num = 0;
        }
    }
    scanf("%d", &I);    

    if (type[0] == 'i') {
        // int
        sum += factor * I * sizeof(int);
    } else if (type[0] == 's') {
        // short
        sum += factor * I * sizeof(short);
    } else {
        // char
        sum += factor * I * sizeof(char);
    }

    printf("%X\n", sum);

    return 0;
}