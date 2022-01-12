#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

void solveOdd(ll x, ll y)
{
    ll ans;
    if (x >= y)
        ans = (x - 1) * (x - 1) + y;
    else
        ans = (y - 1) * (y - 1) + 2 * y - x;

    cout << ans << '\n';
}

void solveEven(ll x, ll y)
{
    ll ans;
    if (x >= y)
        ans = (x - 1) * (x - 1) + 2 * x - y;
    else
        ans = (y - 1) * (y - 1) + x;

    cout << ans << '\n';
}

void solve()
{
    ll x, y;
    cin >> x >> y;

    bool xOdd = (x & 1);
    bool yOdd = (y & 1);

    if (x >= y)
    {
        if (xOdd)
            solveOdd(x, y);
        else
            solveEven(x, y);
    }
    else
    {
        if (yOdd)
            solveOdd(x, y);
        else
            solveEven(x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    while (n--)
        solve();

    return 0;
}