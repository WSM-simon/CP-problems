#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 403;

ll N, rb[Max], rb_prefix[Max], dp[Max][Max], ans = 0;

ll rb_sum(int i, int j) {
    return rb_prefix[j] - rb_prefix[i - 1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> rb[i], ans = max(ans, rb[i]);

    for (int i = 1; i <= N; ++i)
        for (int j = i; j <= N; ++j)
            dp[j][i] = 1;
            
    for (int i = 1; i <= N; ++i)
        rb_prefix[i] = rb_prefix[i - 1] + rb[i];

    for (int i = 1; i <= N; ++i)
        if (rb[i] == rb[i + 1])
            dp[i][i + 1] = 1, ans = max(ans, rb[i] + rb[i + 1]);

    for (int i = 1; i <= N; ++i)
        if (rb[i] == rb[i + 2])
            dp[i][i + 2] = 1, ans = max(ans, rb[i] + rb[i + 1] + rb[i + 2]);

    // dp, search from i to i+k
    // dp[i][j] weather range [i,j] could combine
    for (int k = 2; k < N; ++k) {
        for (int i = 1; i + k <= N; ++i) {
            int p1 = i, p2 = i + k;
            while (p1 < p2) {
                if (rb_sum(i, p1) != 0 && rb_sum(i, p1) == rb_sum(p2, i + k) && dp[i][p1] * dp[p1 + 1][p2 - 1] * dp[p2][i + k] == 1) {
                    dp[i][i + k] = 1, ans = max(ans, rb_sum(i, i + k));
                    break;
                } else if (rb_sum(i, p1) > rb_sum(p2, i + k))
                    p2--;
                else
                    p1++;
            }
        }
    }

    cout << ans;
    return 0;
}
