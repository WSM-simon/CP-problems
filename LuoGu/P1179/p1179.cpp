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

    int a, b;
    cin >> a >> b;
    ll cnt = 0;
    for (int i = a; i <= b; ++i)
    {
        int n = i;
        while(n!=0)
        {
            if (n%10==2)
                cnt++;
            n/=10;
        }
    }
    cout << cnt;
    return 0;
}
