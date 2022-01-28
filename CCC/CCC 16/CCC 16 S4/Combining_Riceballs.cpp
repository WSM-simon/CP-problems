#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 403;

int N, dp[Max][Max], ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> dp[i][i], ans = max(ans, dp[i][i]);

    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            if (dp[i][i] == dp[j][j])
                dp[i][j] = dp[i][i] + dp[j][j], ans = max(ans, dp[i][j]);

    for (int i = 0; i < N; ++i)
        for (int j = j + 2; j < N; ++j)
            if (dp[i][i] == dp[j][j])
                dp[i][j] = dp[i][i] + dp[i + 1][i + 1] + dp[j][j], ans = max(ans, dp[i][j]);

    // dp, search from i to i+k, j is another pointer inside [i][i+k]
    for (int k = 2; k < N; ++k)
    {
        for (int i = 0; i + k < N; ++i)
        {
            // count for operation 1
            for (int j = 0; j < k; ++j)
                if (dp[i][i + j] == dp[i + j + 1][i + k])
                    dp[i][i + k] = dp[i][i + j] + dp[i + j + 1][i + k], ans = max(ans, dp[i][i + k]);

            // count for operation 2
            for (int j1 = 0; )
            {
                
            }
        }
    }
    
    cout << ans;
    return 0;
}
