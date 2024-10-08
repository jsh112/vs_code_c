/*
    우리나라는 섭씨 온도를 사용하지만 미국에서는 화씨 온도를 사용한다. 화씨 온도를 섭씨 온도로
    바꾸는 프로그램을 작성하여 보자. 변환식은 다음과 같다.

    섭씨온도 = 5/9(화씨온도 - 32)

    입력:
    첫 줄에 화씨온도가 입력된다.
    출력:
    화씨온도 ~도는 섭씨온도 ~입니다.

    여기서 주의할 점은 수식을 입력할 때 5/9가 아닌 5.0/9.0으로 적어줘야 한다
*/

#include <iostream>
using namespace std;

int main(){

    float c_temp, f_temp;
    std::cin >> f_temp;

    c_temp = (5.0/9.0) * (f_temp - 32);

    std::cout << "화씨 온도 " << f_temp << "도는 섭씨온도 " << c_temp << "입니다.\n";

    return 0;
}