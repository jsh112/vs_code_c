/*
    크기가 100인 배열을 1부터 100 사이의 난수로 채우고 배열 요소 중에서 최대값을 찾아보자.
    최댓값을 찾으려면 반복하기 전에 배열의 첫 번째 요소를 최댓값으로 가정하고 두 번째 요소부터 현재의 최댓값과 비교한다/
    더 큰 값이 발견되면 최댓값을 교체한다. 범위-기반 루프를 사용해보자
*/

#include <iostream>
#include <ctime>
using namespace std;

int main(){

    const int N = 10;
    srand(time(NULL));
    int list[N];
    int max;

    for(int& elem : list){
        elem = rand() % 100 + 1;
        std::cout<< elem << " ";
    }
    std::cout << std::endl;
    max = list[0];

    for (auto& elem : list){
        if (elem > max) {max = elem;}
    }
    cout << "max = " << max << endl;

    return 0;
}