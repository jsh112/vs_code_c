// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {

//     int n, num;
//     std::cin >> n;
//     vector<int> v, tmp, ans;
//     for (int i = 0; i < n; i++)
//     {
//         std::cin >> num;
//         v.push_back(num);
//     }
//     vector<int>::iterator iter = v.begin();
//     N = 1;
//     while (ans.size() == n)
//     {
//         if (N < *iter)
//         {
//             while (N <= *iter)
//             {
//                 tmp.push_back(N++);
//             }
//         }
//         else if (tmp.back() >= *iter)
//         {
//             iter++;
//             ans.push_back(tmp.back());
//             tmp.pop_back();
//         }
//     }

//     for (int value : ans)
//     {
//         std::cout << value << '\n';
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, num;
    std::cin >> n;
    vector<int> v, tmp, ans;
    for (int i = 0; i < n; i++)
    {
        std::cin >> num;
        v.push_back(num);
    }

    vector<int>::iterator iter = v.begin();
    vector<int>::iterator tmp_iter = v.begin();
    int N = 1;

    // ans.size() == n 으로 조건 수정
    while (ans.size() < n)
    {
        // iter가 벡터 끝을 넘지 않도록 방지
        if (iter == v.end())
            break;

        if (N < *iter)
        {
            // N을 iter와 같은 값까지 tmp에 추가
            while (N <= *iter)
            {
                tmp.push_back(N++);
            }
        }
        // tmp가 비어 있지 않은지 확인 후 pop_back() 실행
        else if (!tmp.empty() && tmp.back() >= *iter)
        {
            iter++;
            ans.push_back(tmp.back());
            tmp.pop_back();
        }
        else
        {
            break;
        }
    }

    for (int value : ans)
    {
        cout << value << '\n';
    }

    return 0;
}
