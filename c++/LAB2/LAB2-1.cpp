/*
    문제:
    컴퓨터가 숨기고 있는 비밀 코드를 추측하는 게임을 작성해보자. 비밀 코드는 a부터 z 사이의 문자이다.
    컴퓨터는 사용자의 추측을 읽고 자신의 비밀 코드와 비교하여 어디 앞인지 뒤인지 알려줌
    입력:
    소문자 하나
    출력:
    위치를 알려준다
*/

#include <iostream>
using namespace std;

int main(){
    char c, secret_code = 'h';
    std::cout << "비밀코드를 맞춰보세요 : ";
    std::cin >> c;

    if(c < secret_code){
        std::cout << "c 앞에 있음.\n";
    }
    else if(c == secret_code){
        std::cout << "맞췄습니다.\n";
    }
    else{
        std::cout << "c 뒤에 있음.\n";
    }

    return 0;
}