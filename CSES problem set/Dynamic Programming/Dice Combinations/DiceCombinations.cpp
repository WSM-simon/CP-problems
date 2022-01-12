#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e6 + 1, Mod = 1e9 + 7;
ll dp[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    dp[0] = 1;
    for (int i = 1; i < 6; i++)
        dp[i] = 1 << i;

    for (int i = 6; i < n; i++)
    {
        dp[i] = accumulate(dp + i - 6, dp + i, 0ll) % Mod;
    }

    cout << dp[n - 1] % Mod;
    return 0;
}