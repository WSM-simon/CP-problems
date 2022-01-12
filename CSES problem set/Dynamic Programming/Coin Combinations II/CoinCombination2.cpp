#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e6 + 3;
const int Mod = 1e9 + 7;
int N, target, dp[Max];
vector<int> coins;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> target;
    for (int i = 0; i < N; ++i)
    {
        int t;
        cin >> t;
        coins.push_back(t);
    }

    dp[0] = 1;
    for (int c : coins)
        for (int i = 1; i <= target; ++i)
            if (i >= c)
                dp[i] = (dp[i] + dp[i - c]) % Mod;

    cout << dp[target];
    return 0;
}