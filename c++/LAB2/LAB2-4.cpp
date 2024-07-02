/*
    if문과 do-while문을 동시에 사용하는 예제이고 숫자를 맞추는 게임이다
    프로그램은 1-100 사이의 정수를 저장하고 있고 사용자는 질문을 통해 값을 맞추려고 노력한다
    시도 회수도 출력한다
*/

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int ans = rand() % 100;
    int guess, tries = 0;

    do
    {
        std::cout << "Guess the answer\n";
        std::cin >> guess;
        tries++;

        if(guess > ans){
            std::cout << "제시한 정수가 높습니다.\n";
        }
        if(guess < ans){
            std::cout << "제시한 정수가 낮습니다.\n";
        }
    } while (guess != ans);

    std::cout << "축하합니다. 시도회수는 " << tries << std::endl;

    return 0;
}