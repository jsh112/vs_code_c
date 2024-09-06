#include <iostream>
#include <complex>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// PI 값 저장
const double PI = acos(-1);

// complex <double> 형태를 cpx라는 이름으로 사용하기 위해 선언
// complex<double>는 인자가 없으면 0+0i, 인자가 한개면 a+0i, 두 개면 a+bi가 된다.
typedef complex<double> cpx;

// (n-1)차 다항식 f를 n개의 복소수로 DFT함 이때 x = w
// DFT : n개의 서로 다른 복소수값이 주어졌을 때 어떤 원칙에 따라 n개의 다른 복소숫값으로 변환하는 것
void FFT(vector<cpx> &f, cpx w)
{
    int n = f.size();
    // base case : 원소가 하나뿐이면 그때 멈춤
    if (n == 1)
        return;

    // 다항식을 index에 따라서 even과 odd로 분리(각 항은 n/2개로 이루어져있다)
    vector<cpx> even(n / 2), odd(n / 2);
    for (int i = 0; i < n; i++)
    {
        (i % 2 ? odd : even)[i / 2] = f[i];
    }

    // 분할과정 : 자기 자신을 재귀적으로 불러와서 계속해서 분할한다
    FFT(even, w * w);
    FFT(odd, w * w);

    // cpx(complex<double>) 선언 -1 + 0i
    cpx wp(1);

    // 정복 과정 : 분할한 친구들을 f(wp) / f(-wp)를 이용해서 정복한다

    for (int i = 0; i < n / 2; i++)
    {
        // f(x) = f_even(x^2) + x * f_odd(x^2)
        f[i] = even[i] + wp * odd[i];
        // 뒤쪽 f(-x) = f_even(x^2) - x * f_odd(x^2)
        f[i + n / 2] = even[i] - wp * odd[i];
        wp *= w;
    }
}

// 두 다항식 a, b를 곱한 c를 계산해서 돌려주는 함수. i번째 원소는 x^i의 개수
vector<cpx> multiply(vector<cpx> a, vector<cpx> b)
{
    // 다항식의 길이보다 큰 최소의 2의 거듭제곱수를 찾아 n으로 둔다
    int n = 1;
    while (n < a.size() + 1 || n < b.size() + 1)
        n *= 2;
    n *= 2;
    a.resize(n);
    b.resize(n);
    vector<cpx> c(n);

    cpx w(cos(2 * PI / n), sin(2 * PI / n));

    // FFT를 통해 두 다항식을 DFT해둔다.
    FFT(a, w);
    FFT(b, w);

    // DFT한 값들끼리 곱하면 결과 다항식의 DFT값이 된다.
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i] * b[i];
    }

    // 역변환 : c의 DFT 값으로부터 c의 다항식 형태를 복원한다.
    FFT(c, cpx(1) / w);
    for (int i = 0; i < n; i++)
    {
        c[i] /= cpx(n);
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }
    return c;
}

int main()
{
    vector<cpx> x, y, z;
    // 띄어쓰기 나오면 그만 넣는다

    while (1)
    {
        char c = getchar();
        if (c == ' ')
            break;
        // char값을 정수값으로 변환
        x.push_back(cpx(c - '0'));
    }

    // enter나 문장이 종료되면 그만 넣는다
    while (1)
    {
        char c = getchar();
        if (c == '\n' || c == EOF)
        {
            break;
        }
        y.push_back(cpx(c - '0'));
    }

    // x와 y의 원소들의 순서를 반대로 바꿈
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    // multiply 함수 실행
    z = multiply(x, y);

    // 구한 z값에 생긴 caryy 정리해주기 위해서 len, carry를 만들어주고 ans에 결과값 넣기
    int len = z.size();
    int carry = 0;
    vector<int> ans;

    // 실수 처리
    for (int i = 0; i < len; i++)
    {
        int n = (int)round(z[i].real()) + carry;
        // 2자리가 넘어가면 다음 자리수로 캐리 보내기
        carry = n / 10;
        ans.push_back(n % 10);
    }

    // 마지막 자리(MSB) 정리
    while (carry > 0)
    {
        ans.push_back(carry % 10);
        carry /= 10;
    }

    // 0이 곱해지는 경우를 따로 처리 후 거꾸로 출력
    int i = ans.size() - 1;
    for (; i >= 0; i--)
    {
        if (ans[i] != 0)
        {
            break;
        }
    }
    if (i < 0)
    {
        cout << "0";
    }
    else
    {
        for (; i >= 0; i--)
        {
            cout << ans[i];
        }
    }

    return 0;
}