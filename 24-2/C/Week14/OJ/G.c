#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct time {
    int hour;
    int minute;
    int second;
};

// 이 위로 수정 금지
void sort_time(struct time *data, unsigned int N) {
    size_t j;
    for (size_t i = 1; i < N; i++) {
        j = i - 1;
        struct time key = data[i];
        while (j >= 0 && key.hour < data[j]->hour) {
            data[j + 1]->hour = data[j]->hour;
            data[j + 1]->minute = data[j]->minute;
            data[j + 1]->second = data[j]->second;
            j--;
        }
        data[j] = key;
    }
}
// 이 아래로 수정 금지

int main(int argc, char const *argv[]) {
    struct time data[100] = {0};
    unsigned int N = 0;
    scanf("%u", &N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d:%d:%d", &data[i].hour, &data[i].minute, &data[i].second);
    }

    sort_time(data, N);

    for (size_t i = 0; i < N; i++) {
        printf("%d:%d:%d\n", data[i].hour, data[i].minute, data[i].second);
    }

    return 0;
}
