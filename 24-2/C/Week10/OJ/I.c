#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
int my_strcmp(const char* s1, const char* s2) {
    s1++;
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s2 - *s1;
}

void markAttendance(char* AS, int N, char* list, int M) {
    for (int i = 0; i < N; i++) {
        int found = 0;
        for (int j = 0; j < M; j++) {
            if (my_strcmp(AS, list + j * 11) == 0) {  // 이름 비교
                AS[0] = '.';                          // 출석 체크
                found = 1;
                break;
            }
        }
        if (!found) {
            AS[0] = '-';  // 결석 표시
        }
        AS += 12;  // 다음 이름으로 이동
    }
}
/* 5 3
Alice Bob Charlie David Eva
Alice Charlie Eva */

// 이 아래로 수정 금지

int main(int argc, char const* argv[]) {
    char AttendanceSheet[100][12] = {0};
    char list[100][11] = {0};
    int N = 0, M = 0;
    scanf("%d %d", &N, &M);
    for (size_t i = 0; i < N; i++) {
        AttendanceSheet[i][0] = ' ';
        scanf("%s", AttendanceSheet[i] + 1);
    }
    for (size_t i = 0; i < M; i++) {
        scanf("%s", list[i]);
    }

    markAttendance((char*)AttendanceSheet, N, (char*)list, M);

    for (size_t i = 0; i < N; i++) {
        printf("%s\n", AttendanceSheet[i]);
    }

    return 0;
}