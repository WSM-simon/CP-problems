#include <bits/stdc++.h>
#define ll long long
#define ar3 array<long long, 3>

using namespace std;

const int MxN = 5e3 + 3;
const int MxM = 1e5 + 3;
const ll INF = 1e18 + 7;

ll N, M, graph[MxN], dp[MxN][MxN], ans[MxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(ans, ans + MxN, INF);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> graph[i];
    }
    for (int i = 0; i + 1 < N; ++i) {
        dp[i][i + 1] = abs(graph[i] - graph[i + 1]);
        ans[2] = min(ans[2], dp[i][i + 1]);
    }
    for (int k = 2; k < N; ++k) {
        for (int i = 0; i + k < N; ++i) {
            dp[i][i + k] = dp[i + 1][i + k - 1] + abs(graph[i] - graph[i + k]);
            ans[k + 1] = min(ans[k + 1], dp[i][i + k]);
        }
    }
    cout << 0 << ' ';
    for (int i = 2; i <= N; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
