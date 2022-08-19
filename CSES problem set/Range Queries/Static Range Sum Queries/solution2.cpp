#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxS = 30;

ll N, M, dp[MxN][MxS];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    // find sum
    // pre calculation
    for (ll i = 1; i <= N; ++i) cin >> dp[i][0];
    for (ll j = 1; j < MxS; ++j) {
        for (ll i = 1; i <= N; ++i) {
            if (i + (1 << j) - 1 > N) break;
            dp[i][j] = dp[i][j - 1] + dp[i + (1 << (j - 1))][j - 1];
        }
    }
    for (ll i = 1; i <= M; ++i) {
        ll q1, q2;
        cin >> q1 >> q2;
        ll diff = q2 - q1 + 1;
        ll ans = 0;
        for (ll j = MxS; j >= 0; j--) {
            if ((diff >> j) & 1)
                ans += dp[q1][j], q1 += (1 << j);
        }
        cout << ans << '\n';
    }
    return 0;
}