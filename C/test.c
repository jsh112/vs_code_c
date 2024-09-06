#include <stdio.h>

int main()
{

    const int std_year = 2024;
    const int std_month = 9;
    const int std_day = 3;

    int num[13], adult = 0;
    // 주민등록번호 입력
    for (int i = 0; i < 13; i++)
    {
        scanf("%1d", &num[i]);
    }

    // 1. 7번째 자리가 3, 4, 7, 8이 아니면 모두 성인
    // 2. 2000년생 중에 첫자리가 0, 두번째 자리가 6보다 작으면 성인
    if ((num[6] != 3) && (num[6] != 4) && (num[6] != 7) && (num[6] != 8) || (num[0] == 0 && num[1] < 6))
    {
        adult = 1;
    }

    // 이제 만나이를 계산해보자
    // year가 90인데 7번째 자리가 0, 9 -> 1890년이므로
    // 2024 - 1890 = 134
    int year = 10 * num[0] + num[1];
    int age;
    // 1800년대 -> num[6]가 0,9
    if ((num[6] == 0) || (num[6] == 9))
    {
        age = std_year - year - 1800;
    }
    else if ((num[6] == 1) || (num[6] == 2) || (num[6] == 5) || (num[6] == 6))
    {
        age = std_year - year - 1900;
    }
    else
    {
        age = std_year - year - 2000;
    }

    // 생일에 따라 나이가 바뀌므로
    // 기준은 09월 03일
    // month 변수에 월을 만들고 9보다 작으면 나이를 안빼줘도 된다.
    // 문제는 9월부터 12월
    // 10~12월은 무조건 나이를 하나 빼줘야 한다.
    // 9월에서는 3보다 크면 무조건 나이를 하나 빼주면 된다.

    int month = 10 * num[2] + num[3];
    int day = 10 * num[4] + num[5];

    if (month > std_month)
    {
        age--;
    }
    else if (month == std_month)
    {
        if (day > std_day)
        {
            age--;
        }
    }

    if (adult)
    {
        printf("%d yes", age);
    }
    else
    {
        printf("%d no", age);
    }

    return 0;
}