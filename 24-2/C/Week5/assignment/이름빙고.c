#include <stdio.h>

int my_strcmp(char *str1, char *str2)
{
    // 문자열 비교를 위해 반복
    // 문자열은 문자(char)의 나열
    // 앞 글자부터 순서대로 비교하며 문자열의 전체를 비교함
    // 반복의 조건이 다양함 (횟수로 지정되지 않음) -> while을 쓰는 게 편하다.
    while (1)
    {
        if ((*str1 == '\0') || (*str2 == '\0'))
        // 둘 중 한 문자열이라도 문자열의 끝('\0', NULL문자)에 다다르면 종료
        {
            break;
        }

        if (*str1 != *str2)
        // 두 문자열을 비교하다가 다른 문자가 있으면 그만 봐도 됨
        {
            break;
        }

        // 순서대로 다음 글자를 봐야하므로 이동함
        str1++;
        str2++;
    }

    // 둘 다 '\0'이면 0을 반환
    // 둘 중 하나만 '\0'이거나 둘이 다른 글자면, 0이 아닌 어떤 값을 반환
    return (*str1 - *str2);
}

int main(int argc, char const *argv[])
{
    // 3 x 3 크기의 빙고판에 이름을 저장.
    char board[3][3][11] = {0};
    // 부른 이름의 개수를 저장.
    unsigned int N = 0;
    // 부른 이름을 저장.
    char tmp[11] = {0};

    // 3 x 3 크기의 빙고판에 이름을 각각 저장하는 반복
    for (int i = 0; i < 3; i++)
    {
        for (int ii = 0; ii < 3; ii++)
        {
            scanf("%s", board[i][ii]);
        }
    }

    // 부른 이름의 수 입력
    scanf("%u", &N);

    // N개의 문자열을 순서대로 입력받기
    for (int i = 0; i < N; i++)
    {
        scanf("%s", tmp);

        // 입력받은 문자열이 빙고판에 존재하는 지 알아보기 위해 빙고판의 모든 문자열과 비교해본다.
        for (int ii = 0; ii < 3; ii++)
        {
            for (int iii = 0; iii < 3; iii++)
            {
                // 입력받은 문자열과 빙고판의 문자열을 비교
                if (my_strcmp(tmp, board[ii][iii]) == 0)
                {
                    // 둘이 같은 경우
                    board[ii][iii][0] = '.';  // 빙고판의 글자를 '.'으로 바꿈
                    board[ii][iii][1] = '\0'; // '.' 하나만 존재하면 되므로 NULL문자로 마감.
                }
            }
        }
    }

    // 수정이 완료된 빙고판 출력
    for (int i = 0; i < 3; i++)
    {
        for (int ii = 0; ii < 3; ii++)
        {
            printf("%s ", board[i][ii]);
        }
        printf("\n");
    }

    return 0;
}
