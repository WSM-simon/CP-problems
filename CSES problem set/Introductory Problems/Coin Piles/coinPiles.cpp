#include <bits/stdc++.h>
#define ll long long
#define pii pair<int int>

using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;

    int mx = max(a, b);
    int mn = min(a, b);

    if (mn * 2 < mx)
        cout << "NO" << '\n';
    else if ((2 * mn - mx) % 3 != 0)
        cout << "NO" << '\n';
    else
        cout << "YES" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    while (n--)
        solve();

    return 0;
}