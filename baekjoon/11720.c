/*
    문제:
    N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.
    입력:
    첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에 숫자 N개가 공백없이 주어진다.
    출력:
    입력으로 주어진 숫자 N개의 합을 출력한다.
*/
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    char digits[101]; // 최대 100자리 숫자 + 널 문자('\0') 고려
    scanf("%s", digits);

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += digits[i] - '0'; // 각 문자를 정수로 변환하여 합산
    }

    printf("%d\n", sum);

    return 0;
}
