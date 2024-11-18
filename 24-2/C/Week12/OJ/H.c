#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int grading_test(int *ans, int *my_ans) {
    // 이 위로 수정 금지
    int sum = 0;
    for (int i = 0; i < 45; i++) {
        if (ans[i * 2] == my_ans[i]) {
            sum += ans[i * 2 + 1];
        }
    }
    return sum;
    // 이 아래로 수정 금지
}

int main(int argc, char const *argv[]) {
    int ans[45][2] = {0};
    int check[45] = {0};
    for (size_t i = 0; i < 45; i++)
        scanf("%d", ans[i]);
    for (size_t i = 0; i < 45; i++)
        scanf("%d", ans[i] + 1);
    for (size_t i = 0; i < 45; i++)
        scanf("%d", check + i);

    printf("%d", grading_test((int *)ans, (int *)check));

    return 0;
}
