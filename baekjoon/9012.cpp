// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {

//     int N;
//     std::cin >> N;
//     string str;
//     for (int i = 0; i < N; i++)
//     {
//         std::cin >> str;
//         string ans = "YES";
//         int cnt1 = 0, cnt2 = 0, len = str.length();
//         // if ((str[0] != '(') || (str[len - 1] != ')') || (len % 2 != 0))
//         // {
//         //     ans = "NO";
//         // }
//         for (int j = 0; j < len; j++)
//         {
//             if (str[j] == '(')
//             {
//                 cnt1++;
//             }
//             else
//             {
//                 cnt2++;
//             }
//             if (cnt1 < cnt2 || (len % 2 != 0))
//             {
//                 ans = "NO";
//             }
//         }
//         if (cnt1 != cnt2)
//         {
//             ans = "NO";
//         }
//         std::cout << ans << '\n';
//     }

//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T; // Number of test cases
    cin >> T;

    while (T--)
    {
        string str;
        cin >> str;

        int balance = 0;
        bool isVPS = true;

        for (char ch : str)
        {
            if (ch == '(')
                balance++;
            else
                balance--;

            if (balance < 0)
            {
                isVPS = false;
                break;
            }
        }

        if (balance != 0)
            isVPS = false;

        cout << (isVPS ? "YES" : "NO") << '\n';
    }

    return 0;
}
