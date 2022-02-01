#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;

int N, M, col[Max];
vector<int> adj[Max];

void dfs(int n, int c = 1)
{
    for (int v : adj[n])
    {
        if (col[v] == c)
        {
            cout << "IMPOSSIBLE";
            exit(0);
        }
        if (col[v] == 0)
        {
            col[v] = c ^ -1;
            dfs(v, col[v]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; ++i)
        if (col[i] == 0)
            col[i] = 1, dfs(i);
    for (int i = 1; i <= N; ++i)
        cout << (col[i] == 1 ? 1 : 2) << ' ';

    return 0;
}
