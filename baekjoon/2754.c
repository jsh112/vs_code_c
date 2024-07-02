/*
    2754 : 학점계산
    문제:
    어떤 사람의 C언어 성적이 주어졌을 때, 평점은 몇 점인지 출력하는 프로그램을 작성하시오.
    A+: 4.3, A0: 4.0, A-: 3.7
    B+: 3.3, B0: 3.0, B-: 2.7
    C+: 2.3, C0: 2.0, C-: 1.7
    D+: 1.3, D0: 1.0, D-: 0.7
    F: 0.0

    입력: 첫째 줄에 C언어 성적이 주어진다. 성적은 문제에서 설명한 13가지 중 하나이다.
    출력: 첫째 줄에 C언어 평점을 출력한다.
*/

#include <stdio.h>
#include <string.h>

int main(){

    char c[3];
    scanf("%s",c);
    float score = 4.0;

    if(c[0] == 'F'){
        printf("0.0\n");
    }

    else{
        score -= c[0] - 'A';
        if(c[1] == '+'){
            score += 0.3;
        }
        else if(c[1] == '-'){
            score -= 0.3;
        }
        printf("%.1f\n",score);
    }

    return 0;
}