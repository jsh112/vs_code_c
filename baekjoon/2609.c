#include <stdio.h>

void swap(int *n1, int *n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // GCD(Greatest Common Divisor : 최대공약수)
    // LCM(Least Common Multiple : 최소공배수)
    int GCD = 1, LCM = 1;
    if (n < m)
    {
        swap(&n, &m);
    }

    int _n = n, _m = m;

    // 최대공약수 구하기 (GCD)
    while (m != 0)
    {
        int temp = m;
        m = n % m;
        n = temp;
    }
    GCD = n;

    // 최소공배수 구하기 (LCM)
    LCM = _n / GCD * _m; // LCM = n * m / GCD is rearranged to avoid overflow

    printf("%d\n%d", GCD, LCM);

    return 0;
}
