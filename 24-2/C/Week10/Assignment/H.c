#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, num;
    scanf("%d %d", &m, &n);
    int *ans = malloc(sizeof(int) * n * m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans[i * n + j] = 0;
            for (int ii = 0; ii < 3; ii++) {
                scanf("%d", &num);
                ans[i * n + j] += num;
            }
            ans[i * n + j] /= 3;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", ans[i * n + j]);
        }
        printf("\n");
    }

    return 0;
}