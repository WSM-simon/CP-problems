#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

set<pii> coster;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        coster.insert({a, 1});
        coster.insert({b, -1});
    }

    int ans = 0;
    int cnt = 0;

    for (pii p : coster)
    {
        cnt += p.second;
        ans = max(ans, cnt);
    }

    cout << ans;
    return 0;
}