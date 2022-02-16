#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
const int inf = 0x3f3f3f3f;

int N, M, dis[Max], par[Max];
bool vis[Max];
vector<int> adj[Max];

void dfs(int n)
{
    vis[n] = 1;
    for (int v : adj[n])
    {
        if (!vis[v])
        {
            dfs(v);
            if (dis[v] + 1 > dis[n])
            {
                dis[n] = dis[v] + 1;
                par[v] = n;
            }
        }
    }
    vis[n] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dis, -0x3f, sizeof(dis));
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    dis[N] = 1;
    dfs(1);
    if (dis[N] < 0)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dis[1] << '\n';
    vector<int> route;
    for (int v = N; v != par[1]; v = par[v])
        route.push_back(v);
    reverse(route.begin(), route.end());
    for (int i = 0; i < dis[N]; ++i)
        cout << route[i] << ' ';
    cout << '\n';

    return 0;
}
