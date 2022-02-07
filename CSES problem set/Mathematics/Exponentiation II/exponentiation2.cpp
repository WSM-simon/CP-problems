#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1;
const int inf = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;

int N;

int binpow(ll a, ll b, ll Mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % Mod;
        a = (a * a) % Mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << binpow(a, binpow(b, c, MOD-1), MOD) << '\n';
    }
    return 0;
}
