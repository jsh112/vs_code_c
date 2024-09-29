// 배열의 시작 주소가 0x1000번지이며,
// 입력한 자료형의 2차원 배열 arr[M][N]이 존재할 때,
// 특정 인덱스의 주소를 출력하는 프로그램을 작성하시오.

// T(문자열) : arr 요소의 자료형 ("char", "int", "short")
// N(정수) : arr의 첫번째 차원의 크기
// M(정수) : arr의 두번째 차원의 크기
// A(정수) : 주소를 출력할 공간의 첫번째 인덱스
// B(정수) : 주소를 출력할 공간의 두번째 인덱스

// N, M, A, B의 값은 문제 D와 동일

#include <stdio.h>

int cmp_str(const char *s1, const char *s2)
{
    int cnt = 0;
    while (s1[cnt] != '\0' && s2[cnt] != '\0')
    {
        if (s1[cnt] != s2[cnt])
        {
            return 0;
        }
        cnt++;
    }
    return 1;
}

int main()
{

    char str[10];
    gets(str);
    int N, M, A, B;
    scanf("%d %d %d %d", &N, &M, &A, &B);

    if (cmp_str(str, "char"))
    {
        printf("%X\n", 0x1000 + sizeof(char) * ((M * A) + B));
    }
    else if (cmp_str(str, "short"))
    {
        printf("%X\n", 0x1000 + sizeof(short) * ((M * A) + B));
    }
    else
    {
        printf("%X\n", 0x1000 + sizeof(int) * ((M * A) + B));
    }

    return 0;
}