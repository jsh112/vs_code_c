#include <stdio.h>

int main() {
    unsigned int n;
    int a, idx = 0;
    char book[100][100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a == 1) {
            // 공백 조심
            scanf(" %[^\n]", book[idx]);
            idx++;
        } else if (a == 2)
            idx--;
    }

    if (idx <= 0) {
        printf("nothing");
    } else {
        for (int i = 0; i < idx; i++) {
            printf("%s\n", book[i]);
        }
    }

    return 0;
}