/*
    사용자로부터 영문자를 받아서 자음과 모음의 개수를 세는 프로그램을 작성하여 보자.
    모음보다는 자음이 훨씬 많으므로 default를 이용하여 자음을 세도록 하자.
    입력:
    자음 또는 모음이 들어옴
    출력:
    자음은 첫번째, 모음은 두번째 줄에 출력
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{

    int vowel = 0, consonant = 0;
    char ch;

    std::cout << "영문자를 입력하고 Control-Z를 치세요\n";
    while (std::cin >> ch)
    {
        while (isalpha(ch))
        {
            switch (ch)
            {
            case 'a':
            case 'i':
            case 'e':
            case 'o':
            case 'u':
            case 'A':
            case 'I':
            case 'E':
            case 'O':
            case 'U':
                vowel++;
                break;
            default:
                consonant++;
                break;
            }
        }
    }
    std::cout << "모음 : " << vowel << endl;
    std::cout << "자음 : " << consonant << endl;

    return 0;
}