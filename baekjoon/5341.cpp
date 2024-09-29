#include <iostream>
using namespace std;
int main()
{

    int start;
    do
    {
        std::cin >> start;
        if (start == 0)
        {
            return 0;
        }
        int sum = 0;
        for (auto i = 1; i <= start; i++)
        {
            sum += i;
        }
        std::cout << sum << endl;
    } while (start != 0);

    return 0;
}