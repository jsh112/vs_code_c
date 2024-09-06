#include <stdio.h>
#include <string.h>

// 1. 문자를 입력받아 ASCII code값을 출력하는 프로그램
void prob1();

// 2. 문자열을 입력받아 모든 공백문자를 삭제하여 출력
void prob2();

// 3. 문자열 안에 특정 문자가 몇개나 포함되어 있는지
// 개수 출력하는 프로그램
void prob3();

// 4. 문자열에서 각 알파벳의 빈도수를 출력하는 프로그램
void prob4();

int main()
{
    // prob1();

    // prob2();

    // prob3();

    prob4();

    return 0;
}

void prob1()
{
    char c;
    scanf("%c", &c);
    printf("%d\n", c);
}

void prob2()
{
    char ch[100];
    gets(ch);
    int len = 0;
    int j = 0;

    for (int i = 0; i < 100; i++)
    {
        if (ch[i] == '\0')
        {
            break;
        }
        else
        {
            len++;
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (ch[i] != ' ')
        {
            printf("%c", ch[i]);
        }
    }
}

void prob3()
{
    char c, ch[100];
    int len = 0, i = 0, cnt = 0;
    gets(ch);
    scanf("%c", &c);
    while (ch[i] != '\0')
    {
        len++;
        i++;
    }
    for (int i = 0; i < len; i++)
    {
        if (ch[i] == c)
        {
            cnt++;
        }
    }
    printf("%s 안에는 %c가 %d개 있습니다.", ch, c, cnt);
}

void prob4()
{
    char ch[100];
    // a : 0, b : 1, ...
    int alpha[52] = {0};
    gets(ch);
    int len = strlen(ch);

    for (int i = 0; i < len; i++)
    {
        if (ch[i] == ' ')
        {
            continue;
        }
        else if ((ch[i] >= 'A') && (ch[i] <= 'Z'))
        {
            // Capital
            alpha[ch[i] - 65 + 26]++;
        }
        else
        {
            // lower
            alpha[ch[i] - 97]++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%c : %d", 'a' + i, alpha[i]);
        printf("\n");
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%c : %d", 'A' + i, alpha[i + 26]);
        printf("\n");
    }
}