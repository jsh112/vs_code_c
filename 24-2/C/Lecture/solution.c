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

int main()
{

    unsigned int data[10] = {0};
    unsigned int N;
    for (int i = 0; i < 10; i++)
    {
        scanf("%X", data + i);
    }

    scanf("%u", &N);

    for (int i = 0; i < 80; i++)
    {
        int t = i + N;

        int iidx = i / 8;
        int imask = (0x80 >> (i % 8));

        int tidx = t / 8;
        int tmask = (0x80 >> (t % 8));

        int b = 0;
        if (t < 80)
        {
            b = data[tidx] & tmask;
        }
        if (b == 0)
        {
            data[iidx] &= ~imask;
        }
        else
        {
            data[iidx] |= imask;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%X ", data[i]);
    }

    return 0;
}