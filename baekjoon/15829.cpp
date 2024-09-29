#include <iostream>
#include <string>

using namespace std;
int main()
{
    const long long M = 1234567891, pow = 31;
    long long N, sum = 0, r = 1;
    std::cin >> N;

    string str;
    std::cin >> str;

    for (long long i = 0; i < N; i++)
    {
        long long value = str[i] - 'a' + 1;
        sum = (sum + value * r) % M;
        r = (r * pow) % M;
    }

    std::cout << sum;

    return 0;
}

/* int main()
{
    // my code

    long long N, M = 1234567891, sum = 0, r = 1, pow = 31;
    std::cin >> N;
    char str[N];
    for (long long i = 0; i < N; i++)
    {
        std::cin >> str[i];
        str[i] -= 96;
    }

    for (long long i = 0; i < N; i++)
    {
        if (i != 0)
        {
            r = (r * pow) % M;
        }
        sum += ((str[i] * r) % M) % M;
    }
    sum %= M;
    std::cout << sum;

    return 0;
} */