#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    ll x, y;
    cin >> x >> y;
    ll m = max(x, y);
    cout << m * m - m + 1 + (x - y) * ((m & 1) ? -1 : 1) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}