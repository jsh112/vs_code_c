/*
    사람들 10명(사람1, 사람2, ...) 에게 아침에 먹는 사과의 개수를 입력하도록 요청하는 프로그램을 작성한다.
    데이터가 입력되면 프로그램은 데이터를 분석하여 누가 가장 많은 사과를 아침으로 먹었는지 출력한다.
*/

#include <iostream>
using namespace std;

int main(){

    const int N = 10;
    int list[N];
    int max, person;

    for (int& i : list){
        std::cout << "아침에 먹는 사과의 개수 : ";
        std::cin >> i;
    }
    std::cout << endl;
    max = list[0];
    person = 0;

    for (int i = 0; i < N; i++){
        if(list[i] > max){
            max = list[i];
            person = i;
        }
    }

    std::cout << "가장 많은 사과를 먹은 사람 번호 : " << person + 1 << std::endl;

    return 0;
}