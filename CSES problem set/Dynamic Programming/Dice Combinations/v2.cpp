#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e2 + 1, Mod = 1e9 + 7;
ll dp[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= min(6, i); j++)
            dp[i] = (dp[i] + dp[i - j]) % Mod;

    cout << dp[n] % Mod;
    return 0;
}