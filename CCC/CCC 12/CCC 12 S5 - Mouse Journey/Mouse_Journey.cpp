#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 30;

int R, C, K, dp[Max];
bool cats[Max][Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    cin >> K;
    while (K--)
    {
        int u, v;
        cin >> u >> v;
        cats[u][v] = 1;
    }

    dp[1] = 1;
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            if (cats[i][j])
                dp[j] = 0;
            else
                dp[j] += dp[j - 1];
        }
    }

    cout << dp[C];
    return 0;
}