#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const ll Mod = 1e9 + 7;
const int Max = 1e6 + 3;
ll N, M, dp[Max];
vector<int> coins;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int tem;
        cin >> tem;
        coins.push_back(tem);
    }

    dp[0] = 1;

    for (ll i = 1; i <= M; ++i)
        for (ll c : coins)
            if (i - c >= 0)
                dp[i] = (dp[i] + dp[i - c]) % Mod;

    cout << dp[M];
    return 0;
}