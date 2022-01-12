#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int MOD = 1e9 + 7;
const int Max = 1e5 + 3;
int N, M, dp[Max];
bool vis[Max];
vector<int> adj[Max];

void dfs(int n)
{
    vis[n] = 1;
    for (int v : adj[n])
    {
        if (!vis[v])
            dfs(v);
        dp[n] = (dp[v] + dp[n]) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
    }

    dp[N] = 1;
    dfs(1);
    cout << dp[1];
    return 0;
}