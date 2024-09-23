// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

// int solution(int a, int b, int c)
// {
//     int answer = 0;
//     answer = a + b + c;
//     if (a == b || a == c || b == c)
//     {
//         answer *= a * a + b * b + c * c;
//         if (a == b && a == c)
//             answer *= a * a * a + b * b * b + c * c * c;
//     }
//     return answer;
// }

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int power(int x, int y, int z, int n)
{
    int _x = x, _y = y, _z = z;
    for (int i = 0; i < n - 1; i++)
    {
        _x *= x;
        _y *= y;
        _z *= z;
    }
    return (_x + _y + _z);
}

int solution(int a, int b, int c)
{
    if ((a != b) && (b != c) && (c != a))
    {
        return (a + b + c);
    }
    else if ((a == b) || (b == c) || (c == a))
    {
        if ((a == b) && (b == c))
        {
            return (a + b + c) * power(a, b, c, 2) * power(a, b, c, 3);
        }
        else
        {
            return (a + b + c) * power(a, b, c, 2);
        }
    }
}

int main()
{

    printf("%d", solution(4, 4, 4));

    return 0;
}