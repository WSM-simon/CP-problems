#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e3 + 3;
const int Max2 = 1e5 + 3;

int N, M, costs[Max], books[Max], dp[Max][Max2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> costs[i];
    for (int i = 1; i <= N; ++i)
        cin >> books[i];
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            dp[i][j] = max(dp[i - 1][j], j - costs[i] >= 0 ? dp[i - 1][j - costs[i]] + books[i] : 0);

    cout << dp[N][M];
    return 0;
}