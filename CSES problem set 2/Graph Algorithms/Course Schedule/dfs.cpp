#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
int N, M;
bool vis[Max];
vector<int> adj[Max], topo;

// worked only for DAG, doesn't work for a cyclic graph
bool dfs(int n)
{
    for (int v : adj[n])
        if (!vis[v])
        {
            vis[v] = 1;
            dfs(v);
        }
    topo.push_back(n);
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

    for (int i = 1; i <= N; ++i)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(i);
        }
    }

    if (topo.size() == N)
    {
        reverse(topo.begin(), topo.end());
        for (int v : topo)
            cout << v << ' ';
    }
    else
        cout << "IMPOSSIBLE";

    return 0;
}