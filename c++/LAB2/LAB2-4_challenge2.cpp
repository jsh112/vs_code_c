/*
    사용자가 어떤 숫자를 생각하던 간에 7번 이하의 추측으로 컴퓨터가 맞출 수 있도록 프로그램을 수정하라
*/

#include <iostream>
#include <string>
#include <ctime>
#define N 99
using namespace std;

int main()
{

    srand(time(NULL));
    int answer, lower = 1, upper = N, tries = 0;
    string str;
    std::cout << "사용자가 생각하는 비밀번호(1-99)를 입력해주세요.\n";
    std::cin >> answer;

    do
    {
        int guess = (lower + upper) / 2;
        std::cout << "제가 예측한 숫자는 " << guess << "입니다.\n";
        tries++;

        if (guess == answer)
        {
            cout << "정답을 맞췄습니다. 시도 회수는 " << tries << "회입니다.\n";
            break;
        }
        else if (guess < answer)
        {
            cout << "더 높은 숫자입니다.\n";
            lower = guess + 1; // 추측이 작으면 범위를 높은 쪽으로 조정
        }
        else
        {
            cout << "더 낮은 숫자입니다.\n";
            upper = guess - 1; // 추측이 크면 범위를 낮은 쪽으로 조정
        }
    } while (lower <= upper);

    return 0;
}