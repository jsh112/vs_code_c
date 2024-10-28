#include <stdio.h>

// int main()
// {

// unsigned char a = 0x11;
// char str1[100];
// char str2[100];
// scanf("%hhX", &a);

// scanf("%s") -> 공백까지 못받음
// scanf("%[^\n]",str) -> 공백 전까지 받는다

/*
    scanf("%[^\n]", str1);
    scanf("\n%[^\n]",str2);
    scanf(" %[^\n]",str2); -> 개행문자 하나 건너뛰고 입력받음
*/

/*

    char c;
    scanf(" %c", &c);
    -- > 앞에 있는 whitespace들을 제거하고
    유의미한 문자들을 받아달라
*/

/*
    scanf("%s %[^[]"); -> 여는 대괄호 앞까지 입력 받아달라
    scanf("%s %[^[][%d];")
    // int arr[10]; 이 들어올 때 받아줌
*/
/* int sz;
char str1[100];
char str2[100];
printf("입력 예: foo bar[42];\n");
scanf("%s %[^[][%d];", str1, str2, &sz);

// 입력된 결과를 출력
printf("%s %s %d\n", str1, str2, sz);
return 0; */
// }

/**
 * 10바이트 << shift 연산 구현
 */

#define BIT 8
#define SZ 10
void left_shift(unsigned char *arr, int n)
{
    int srcbyte_idx, dstbyte_idx;
    for (int i = 0; i < BIT * SZ; i++)
    {
        int t = i + n;

        dstbyte_idx = i / BIT;
        int dst = (0x80 >> (i % BIT));

        srcbyte_idx = t / BIT;
        int src = (0x80 >> (t % BIT));

        int b = 0;
        if (t < 80)
            b = arr[srcbyte_idx] & src;
        if (b == 0)
            arr[dstbyte_idx] &= ~dst;
        else
            arr[dstbyte_idx] |= dst;
    }
}

void right_shift(unsigned char *arr, int N)
{
    int srcbyte_idx, dstbyte_idx;
    for (int i = BIT * SZ - 1; i >= 0; i--)
    {
        int t = i - N;

        dstbyte_idx = i / BIT;
        int dst = (0x80 >> (i % BIT));
        srcbyte_idx = t / BIT;
        int src = (0x80 >> (t % BIT));

        int b = 0;
        if (t >= 0)
            b = arr[srcbyte_idx] & src;
        if (b == 0)
            arr[dstbyte_idx] &= ~dst;
        else
            arr[dstbyte_idx] |= dst;
    }
}

int main()
{

    unsigned char data[10] = {0};
    unsigned int N;
    for (int i = 0; i < 10; i++)
    {
        scanf("%hhX", data + i);
    }

    scanf("%u", &N);

    right_shift(data, N);

    for (int i = 0; i < 10; i++)
    {
        printf("%X ", data[i]);
    }

    return 0;
}