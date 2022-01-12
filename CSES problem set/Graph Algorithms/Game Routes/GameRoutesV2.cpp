#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
const int Mod = 1e9 + 7;
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
        dp[n] = (dp[n] + dp[v]) % Mod;
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
        adj[v2].push_back(v1);
        // reversed adj list
    }
    dp[1] = 1;
    dfs(N);
    cout << dp[N];
    return 0;
}