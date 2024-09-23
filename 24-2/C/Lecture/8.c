#include <stdio.h>

int main()
{
    char a[50] = {0}; // 모든 요소를 0으로 초기화
    a[0] = -1;        // 255로 해석
    a[1] = 'A';       // 유효한 아스키 문자
    a[2] = '\0';      // 문자열 종료

    printf("첫 번째 문자의 ASCII 값: %d\n", a[0]); // -1 또는 255
    printf("문자열: %s\n", a);                     // "A"만 출력됨
    printf("나머지 요소들: ");
    for (int i = 3; i < 50; i++)
    {
        printf("%d ", a[i]); // 모두 0으로 출력됨
    }
    printf("\n");

    return 0;
}