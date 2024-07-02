/*
    문제 2-4를 수정한다. 사용자가 비밀리에 결정한 번호를 컴퓨터가 추측하도록 하라.
    사용자는 컴퓨터가 추측한 숫자가 높거나 낮은지를 컴퓨터에 알려야 한다.
*/

#include <iostream>
#include <ctime>
using namespace std;

int main(){

    srand(time(NULL));
    int answer = 84, guess, tries = 0;
    int lower = 1, upper = 100;
    string str;

    do {
        // lower
        // guess ~ upper
        // guess + rand() % (upper - guess)
        // 만약 75면 lower, lower = 76
        // 76 + rand() % (100 - 76) -> 76 + rand() % 24 = 76 + (0 ~ 23) = 76 ~ 99가 나옴

        // higher
        // 만약 90이면 higher
        // lower + rand() % (guess - lower) (lower 1정도로 잡자)
        // 1 + rand() % (90 - 1) = 1 + rand() % 89 = 1 + (0 ~ 88) = 1 ~ 89
        guess = lower + rand() % (upper - lower);
        std::cout << "제가 추측하는 수는 " << guess << "입니다.\n";
        tries++;

        std::getline(cin,str);
        if (str == "lower"){
            lower = guess + 1;
        }
        else if (str == "higher"){
            upper = guess;
        }
        else if (str == "correct"){
            std::cout << "축하합니다. 시도횟수는 " << tries << std::endl;
            break;
        }
        else{
            std::cout << "잘못된 입력입니다. 낮습니다/높습니다로 답해주세요\n";
        }
    } while (true); 

    return 0;
}