#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Fish {
    unsigned int length;
    unsigned int time;
    char type[20];
};

int main(int argc, char const *argv[]) {
    struct Fish fishes[10];

    for (int i = 0; i < 10; i++) {
        scanf("%u %u %s", &fishes[i].length, &fishes[i].time, fishes[i].type);
    }

    // 이 위로 수정 금지
    int sum = 0, min = 100, idx;
    for (int i = 0; i < 10; i++) {
        sum += fishes[i].length;
        if (min > fishes[i].time) {
            min = fishes[i].time;
            idx = i;
        }
    }

    sum /= 10;
    printf("%d %s", sum, fishes[idx].type);
    // 이 아래로 수정 금지

    return 0;
}