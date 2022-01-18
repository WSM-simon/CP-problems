#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e3 + 3;
const int Mod = 1e9 + 7;

int N, dp[Max][Max];
char grid[Max][Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j];

    // init for DP
    for (int j = 0; j < N; ++j)
    {
        if (grid[0][j] != '*')
            dp[0][j] = 1;
        else
            break;
    }

    for (int i = 0; i < N; ++i)
    {
        if (grid[i][0] != '*')
            dp[i][0] = 1;
        else
            break;
    }

    // start DP!!
    for (int i = 1; i < N; ++i)
        for (int j = 1; j < N; ++j)
            if (grid[i][j] != '*')
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % Mod;

    cout << dp[N-1][N-1];
    return 0;
}