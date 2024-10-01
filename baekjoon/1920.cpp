#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int max_idx = 100001;
    int n;
    std::cin >> n;
    std::vector<std::tuple<int, int, string>> people;

    for (int i = 0; i < n; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        people.push_back(make_tuple(age, i, name));
    }

    std::sort(people.begin(), people.end(), [](const auto &a, const auto &b)
              {
        if (get<0>(a) != get<0>(b)){
            return get<0>(a) < get<0>(b);
        }
        return get<1>(a) < get<1>(b); });
    for (const auto &person : people)
    {
        cout << get<0>(person) << " " << get<2>(person) << "\n"; // 나이, 이름 출력
    }

    return 0;
}