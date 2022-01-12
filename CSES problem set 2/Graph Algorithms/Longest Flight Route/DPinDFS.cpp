#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
const int inf = 0x3f3f3f3f;

int N, M, dis[Max], par[Max];
vector<int> adj[Max];
bool vis[Max];

void dfs(int n)
{
    for (int v : adj[n])
    {
        if (!vis[v])
        {
            vis[v] = 1;
            dfs(v);
        }
        if (dis[n] < dis[v] + 1)
        {
            dis[n] = dis[v] + 1;
            par[n] = v;
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
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
    }

    memset(dis, -0x3f, sizeof(dis));
    dis[N] = 0;
    dfs(1);
    if (dis[1] < 0)
        cout << "IMPOSSIBLE\n";
    else
    {
        cout << dis[1] + 1 << '\n';
        vector<int> ans;
        for (int v = 1; v != 0; v = par[v])
            cout << v << ' ';
    }
    return 0;
}