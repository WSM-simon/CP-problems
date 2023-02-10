#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 403;

int N, dp[Max][Max], ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> dp[i][i], ans = max(ans, dp[i][i]);

    for (int i = 0; i < N; ++i)
        if (dp[i][i] == dp[i + 1][i + 1])
            dp[i][i + 1] = dp[i][i] + dp[i + 1][i + 1], ans = max(ans, dp[i][i + 1]);

    for (int i = 0; i < N; ++i)
        if (dp[i][i] == dp[i + 2][i + 2])
            dp[i][i + 2] = dp[i][i] + dp[i + 1][i + 1] + dp[i + 2][i + 2], ans = max(ans, dp[i][i + 2]);

    // dp, search from i to i+k, j is another pointer inside [i][i+k]
    for (int k = 2; k < N; ++k) {
        for (int i = 0; i + k < N; ++i) {
            int p1 = i, p2 = i+k;
            for (int )
        }
    }

    cout << ans;
    return 0;
}
