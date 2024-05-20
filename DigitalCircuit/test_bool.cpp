#include <iostream>

using namespace std;

int main() {
    bool A, B, F;

    cout << "A B F" << endl;

    for(int i = 0; i < 4; i++) {
        A = i & 2;  // i의 2번째 비트를 A에 저장
        B = i & 1;  // i의 1번째 비트를 B에 저장

        F = !( (!A || B) );  // F = (A' + B)'

        cout << A << " " << B << " " << F << endl;
    }

    return 0;
}
