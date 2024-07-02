/*
    사용자로부터 받은 3개의 정수 중 가장 큰 수를 찾는 프로그램을 작성해보자
    입력:
    세 숫자가 공백을 두고 입력된다
    출력:
    가장 큰 정수를 출력한다
*/

#include <iostream>
using namespace std;

int main(){

    int a,b,c,largest;
    string str;
    std::cout << "3개의 정수를 입력하시오 : ";
    std::cin >> a >> b >> c;

    if(a > b && a > c) largest = a;
    else if(b > a && b > c) largest = b;
    else largest = c;

    std::cout << "가장 큰 정수는 " << largest << std::endl;

    return 0;
}