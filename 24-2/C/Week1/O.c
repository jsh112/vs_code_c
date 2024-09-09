// 문제 O : 책장 정리

// 문제 설명
// 20개의 책들을 높이에 따라 2개의 책장에 나누어 정리하려한다.
// 주어진 기준에 따라 높이가 그 이상인 그룹은 1번째 배열에 저장하고,
// 그 미만인 그룹인 2번째 배열에 저장한다.

// 입력 설명
// A1 A2 ... A20
// N

// Ai(정수): 처리할 책 높이 배열
// N(정수): 책 높이 기준

// 0 <= Ai < 2^32 (1 <= i <= N)
// 0 <= N < 2^32

// 출력 설명
// 기준보다 낮은 책의 높이들을 첫 줄에 띄어쓰기로 구분하여 출력하고,
// 기준과 같거나 높은 책의 높이들을 그 다음 줄에 띄어쓰기로 구분하여 출력한다.

// 이때, 각 줄은 입력한 순서대로 출력한다.

// 입력 예시
// 22 231 45 12 32 81 90 34 36 54 75 111 136 171 199 232 293 311 377 415
// 120

// 출력 예시
// 22 45 12 32 81 90 34 36 54 75 111
// 231 136 171 199 232 293 311 377 415

// ACCEPTED CODE

#include <stdio.h>

int main()
{
    // f2는 2층, N보다 작거나 같은 높이들
    // f1는 1층, N보다 큰 높이들 저장
    int num = 20;
    unsigned int N, book[num], f2[num], f1[num];
    int cnt2 = 0, cnt1 = 0;
    for (int i = 0; i < num; i++)
    {
        scanf("%u", &book[i]);
    }
    scanf("%u", &N);
    for (int i = 0; i < num; i++)
    {
        if (book[i] < N)
        {
            f2[cnt2++] = book[i];
        }
        else
        {
            f1[cnt1++] = book[i];
        }
    }
    for (int a = 0; a < cnt2; a++)
    {
        printf("%u ", f2[a]);
    }
    printf("\n");
    for (int b = 0; b < cnt1; b++)
    {
        printf("%u ", f1[b]);
    }
    return 0;
}

#include <stdio.h>

int main()
{

    unsigned int N;
    unsigned int book[20];
    for (int i = 0; i < 20; i++)
    {
        scanf("%u", &book[i]);
    }
    scanf("%u", &N);

    // 기준을 넘으면 index1, 못넘으면 index2로
    // case1 : index1, case2 : index2
    int index1 = 0, index2 = 0;
    unsigned int case1[20], case2[20];

    for (int i = 0; i < 20; i++)
    {
        if (book[i] >= N)
        {
            case1[index1++] = book[i];
        }
        else
        {
            case2[index2++] = book[i];
        }
    }

    for (int b = 0; b < index2; b++)
    {
        printf("%u ", case2[b]);
    }
    printf("\n");
    for (int a = 0; a < index1; a++)
    {
        printf("%u ", case1[a]);
    }

    return 0;
}