#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct time {
    int hour;
    int minute;
    int second;
};

// 이 위로 수정 금지
struct time sum_time(struct time t1, struct time t2) {
    struct time tmp;
    int s = t1.second + t2.second;
    int m = t1.minute + t2.minute;
    int h = t1.hour + t2.hour;
    if (s >= 60) {
        m++;
        s -= 60;
    }

    if (m >= 60) {
        h++;
        m -= 60;
    }

    tmp.second = s;
    tmp.minute = m;
    tmp.hour = h;
    return tmp;
}
// 이 아래로 수정 금지

int main(int argc, char const *argv[]) {
    struct time t1, t2;
    scanf("%d:%d:%d", &t1.hour, &t1.minute, &t1.second);
    scanf("%d:%d:%d", &t2.hour, &t2.minute, &t2.second);

    struct time sum = sum_time(t1, t2);

    printf("%02d:%02d:%02d\n", sum.hour, sum.minute, sum.second);

    return 0;
}