#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 53;
int T, dp[Max][Max].dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char grid[Max][Max];

bool isValid(int x, int y, int k, int N) { return x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == '.' && k >= 0; }

void dfs(int x, int y, int m, int k)
{
    grid[x][y] = 'H';
    for (int v :)
}

void solve()
{
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j];

    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    dp[0][0] = 1;
    dfs(0, 0, 1, k);
    cout << dp[N] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}