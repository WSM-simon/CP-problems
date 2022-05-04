#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> N)
    {
        if (N == 0)
            break;
        int a, b;
        for (int i=sqrt(N); i<=N; ++i)
        {
            if (N%i == 0)
            {
                a = i, b = N/i;
                break;
            }
            if (a>b)
                swap(a, b);
        }
        cout << "Minimum perimeter is " << 2*a+2*b << " with dimensions ";
        cout << a << ' ' << 'x' << ' ' << b << '\n';
    }
    return 0;
}
