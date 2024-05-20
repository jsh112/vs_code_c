#include <iostream>
using namespace std;

class Input_2
{
public:
    bool A;
    bool B;

    Input_2(bool a, bool b) : A(a), B(b) {}
};

class Input_3
{
public:
    bool A;
    bool B;
    bool C;

    Input_3(bool a, bool b, bool c) : A(a), B(b), C(c)
    {
    }
};

int main()
{
    // cout << "A B C F1      A B C F2" << endl;
    // for (int i = 0; i < 8; i++)
    // {
    //     bool A = (i >> 2) & 1;
    //     bool B = (i >> 1) & 1;
    //     bool C = i & 1;

    //     Input input(A, B, C);

    //     bool F1 = input.A && !input.B || !input.A && input.C;
    //     bool F2 = !input.A && (!input.B || input.C);
    //     cout << A << " " << B << " " << C << " " << F1 << "       "<< A << " " << B << " " << C << " " << F2 <<endl;
    // }

    cout << "A B C D F1" << endl;

    for (int i = 0; i < 16; i++)
    {
        bool a = (i >> 3) & 0b1;
        bool b = (i >> 2) & 0b1;
        bool c = (i >> 1) & 0b1;
        bool d = i & 0b1;

        bool F1 = (a || b || !c || d) && (a || !b || c || d) && (a || !b || !c || !d) && (!a || b || c || d) && (!a || b || c || !d) && (!a || b || !c || d) && (!a || b || !c || !d) && (!a || !b || c || !d);
        bool F2 = (!a && !b && !c && !d) || (!a && !b && !c && d) || (!a && !b && c && d)|| (!a && b && !c && d)|| (!a && b && c && !d) || (a && b && !c && !d) || (a && b && c && d) || (a && b && c && !d); 
        if (i % 4 == 3) cout << endl;
        cout << a << " " << b << " " << c << " " << d << " " << F1 <<" "<<  a <<" "<<b<<" "<<c<<" "<<d<<" "<<F2<<endl;
    }
}