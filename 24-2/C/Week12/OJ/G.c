#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char mj[n][60];
    int c_score[n], t_score[n];
    int sum[n];

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", &mj[i], &t_score[i], &c_score[i]);
        sum[i] = 0;
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < t_score[i]) {
            max = t_score[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (t_score[i] == max) {
            sum[i] += 50;
        }
        sum[i] += (c_score[i] + t_score[i]);
    }

    int mmax = 0, idx;
    for (int i = 0; i < n; i++) {
        if (mmax < sum[i]) {
            mmax = sum[i];
            idx = i;
        }
    }

    printf("%s", mj[idx]);

    return 0;
}