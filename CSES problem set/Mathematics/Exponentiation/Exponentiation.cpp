#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1;
const int inf = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;

int N;

void binpow()
{
    ll a, b, res = 1;
    cin >> a >> b;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while (N--)
        binpow();
    return 0;
}
