#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    ll ans = -1e18, mss = -1e18;
    for (int i = 0; i < n; i++)
    {
        ll tem;
        cin >> tem;
        mss = max(tem, tem + mss);
        ans = max(mss, ans);
    }
    cout << ans;
    return 0;
}