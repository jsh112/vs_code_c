#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // to ma to -> 0 1 2
    // 0, 2, 4,
    // 0, 0, 0

    // 2명
    // to to ma to
    // 0 1 / 2 3 / 4 5
    // 0 1 / 2 0 / 1 2
    // to ma / to to / ma
    // 3명
    // to to to to
    // 0 1 2 / 3 4 5 / 6 7 8 / 9 10 11 
    // 0 1 2 / 0 1 2 / 0 1 2 / 
    // 4명
    // 0 1 2 3 / 4 5 6 7
    // to ma to to / ma to ma to /
    // to ma to to

    char tm[3][3] = {"to", "ma", "to"};

    for (int i = 0; i < 10; i++) {
        printf("%s ", tm[(i * n) % 3]);
    }

    return 0;
}