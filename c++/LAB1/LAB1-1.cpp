/*
    최대한도의 사탕사기

    철수가 가지고 있는 돈으로 최대한의 사탕을 살고 한다. 현재 1000원이 있고 사탕의 가격이 300원이라고 하자.
    최대한 살 수 있는 사탕의 개수와 나머지 돈은 얼마인가? 정수 나눗셈 연산자 /와 나머지 연산자 %를 사용해보자.

    출력:
    현재 가지고 있는 돈 : 1000
    캔디의 가격 : 300
    최대로 살 수 있는 캔디의 개수 = 3
    캔디 구입 후 남은 돈 = 100
*/

#include <iostream>

int main()
{

    int money, candy_price;

    std::cout << "현재 가지고 있는 돈 : ";
    std::cin >> money;

    std::cout << "캔디의 가격 : ";
    std::cin >> candy_price;

    std::cout << "최대로 살 수 있는 캔디의 개수 = " << (money / candy_price) << std::endl;
    std::cout << "캔디 구입 후 남은 돈 = " << (money % candy_price) << std::endl;
    return 0;
}