#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned int A = 0, N = 0; // 처리할 정수와 비트의 간격을 입력받아 저장
    scanf("%X %u", &A, &N);

    // 읽을 비트의 위치만 1인 mask와, 읽은 비트를 기록할 ans
    unsigned int mask = 0x80; // = 0b1000 0000
    unsigned int ans = 0;

    // 몇 번 반복할 지 모름,
    // 하지만 mask를 움직이면서 읽다가, mask가 0이 될 때 멈추면 됨.
    // 즉, 조건 반복이다(while)
    while (1)
    {
        // 언제 멈춘다? mask가 0이 되면 멈춘다.
        if (mask == 0)
        {
            break;
        }

        // 멈추기 전엔 뭘 해야하는가
        // A에서 특정 위치(mask에 비트가 1인 위치)의 비트를 읽고
        // 그 비트의 정보를 기록(ans)해야함.
        // 기록하면서 2진수로도 출력을 해야함.

        if ((A & mask) != 0)
        // mask와 A를 bit AND 연산.
        // mask에 존재하는 1과 같은 위치에 1이 존재함을 의미.
        {
            ans |= 1;    // ans에 1을 기록함.
            printf("1"); // 1을 출력함
        }
        else
        {
            ans &= (~1); // ans에 0을 기록함. (사실 이미 ans의 최하위 비트는 0이라 없어도 됨)
            printf("0");
        }
        ans = ans << 1; // 비트 단위로 이동하면서 기록한다.
        // ans의 최하위 비트 값을 변경하고, 왼쪽으로 한 칸 밀고, 반복하면 추출한 비트가 모두 저장됨.

        mask = mask >> N; // N 간격에 따라 비트를 읽는 게 목적임.
        // 따라서 mask를 N씩 이동시킨다.
    }
    // N 간격에 따라 비트를 다 읽고 출력도 다 함.
    // 이제 ans를 출력하면 끝.
    // 단, 비트를 기록하고 시프트하기를 반복했기 때문에 시프트가 하나 더 됨.
    // 출력 전에 보정이 필요하다.
    ans = ans >> 1;
    printf("\n%u", ans); // 출력 포맷을 맞추기 위한 개행문자

    return 0;
}
