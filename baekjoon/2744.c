/*
    2744 : 대소문자 바꾸기

    문제:
    영어 소문자와 대문자로 이루어진 단어를 입력받은 뒤, 대문자는 소문자로, 소문자는 대문자로 바꾸어 출력하는 프로그램을 작성하시오.

    출력:
    첫째 줄에 영어 소문자와 대문자로만 이루어진 단어가 주어진다. 단어의 길이는 최대 100이다.

    입력:
    첫째 줄에 입력으로 주어진 단어에서 대문자는 소문자로, 소문자는 대문자로 바꾼 단어를 출력한다.
*/

#include <stdio.h>
#include <string.h>

int main(){

    char c[100];
    scanf("%s",c);

    for(int i=0;i<strlen(c);i++){
        if(c[i] >= 'a' && c[i] <= 'z'){
            c[i] = c[i] - 'a' + 'A';
        }
        else if(c[i] >= 'A' && c[i] <= 'Z'){
            c[i] = c[i] - 'A' + 'a';
        }
    }

    for(int i=0;i<strlen(c);i++){
        printf("%c",c[i]);
    }

    return 0;
}