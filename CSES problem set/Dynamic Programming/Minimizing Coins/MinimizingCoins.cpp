#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 100, Mxx = 1e2 + 1;
int n, x, coins[Max];
ll dp[Mxx];

int main()
{
    // freopen("C:\\Users\\Simian\Downloads\\test_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    for (int i = 1; i <= x; i++)
    {
        dp[i] = INT32_MAX;
        for (int j = 0; j < n; j++)
            if (coins[j] <= i)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    }
    if (dp[x] == INT32_MAX)
        cout << -1 << '\n';
    else
        cout << dp[x];

    return 0;
}