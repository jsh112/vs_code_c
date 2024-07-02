/*
    2개의 주사위를 던져서 주사위의 합을 표시하는 프로그램을 작성해보자.
    주사위를 던지면 랜덤한 수가 나와야 한다. 따라서 난수를 생성하는 코드가 필요하다.

    입력: 
    없음
    출력:
    두 주사위의 눈의 합을 출력한다.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

int main(){

    srand(time(NULL));
    int number1 = (rand()%6) + 1;
    int number2 = (rand()%6) + 1;

    std::cout << "두 주사위 합 = " << number1 + number2 << std::endl;

    return 0;
}