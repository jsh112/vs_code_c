#include <iostream>
const int size = 6;
using namespace std;
int main()
{
    unsigned int N, t_bundle, sum_T = 0, pen_pundle;
    std::cin >> N;
    int T[size];
    for (int i = 0; i < size; i++)
    {
        std::cin >> T[i];
    }
    std::cin >> t_bundle >> pen_pundle;

    for (int i = 0; i < size; i++)
    {
        sum_T += (T[i] + t_bundle - 1) / t_bundle;
    }
    std::cout << sum_T << '\n';
    std::cout << (N / pen_pundle) << " " << (N % pen_pundle) << std::endl;

    return 0;
}