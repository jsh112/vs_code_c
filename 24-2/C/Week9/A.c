#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이 위로 수정 금지
const char *my_strstr(const char *pstr, const char *name) {
    for (; *pstr; pstr++) {
        if (*pstr == *name) {
            const char *start = pstr;
            const char *needle = name;

            while (*needle && *pstr == *needle) {
                pstr++;
                needle++;
            }

            if (!*needle)
                return start;

            pstr = start;
        }
    }
    return NULL;
}

void my_strncat(char *str1, char *str2, size_t len) {
    while (*str1)
        str1++;
    size_t i = 0;
    while (i < len && str2[i]) {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}

void my_strncpy(char *str1, char *str2, size_t len) {
    size_t i = 0;
    while (i < len && str2[i]) {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = 0;
}

// 이 아래로 수정 금지

void changeName(char *str, char *name, char *replace) {
    char tmp[201] = {0};
    char *pstr = str;
    char *p = my_strstr(pstr, name);  // str에 name이 있는지 검사
    int lname = 0;
    while (name[lname])
        lname++;
    while (p)  // name이 있는 만큼 반복
    {
        my_strncat(tmp, pstr, p - pstr);  // name 전까지 복사
        my_strncat(tmp, replace, 100);    // name 대신 replace로 대체
        pstr = p + lname;                 // name의 뒤부터 다시 검사
        p = my_strstr(pstr, name);
    }
    my_strncat(tmp, pstr, 100);  // 나머지 잇기
    my_strncpy(str, tmp, 200);   // 변환한 문자열을 str에 복사
}

int main(int argc, char const *argv[]) {
    char str[201] = {0};
    char name[101] = {0};
    char replace[101] = {0};

    // 문자열 str을 입력받는다
    scanf("%[^\n]\n", str);
    // 문자열 name과 replace를 입력받는다
    scanf("%s %s", name, replace);

    // changeName 함수를 호출하여 문자열을 변경한다
    changeName(str, name, replace);

    // 결과를 출력한다
    printf("%s", str);

    return 0;
}