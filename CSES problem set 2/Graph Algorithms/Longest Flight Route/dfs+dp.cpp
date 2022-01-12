#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int inf = 0x3f3f3f3f;
const int Max = 1e5 + 3;

int N, M, dis[Max], par[Max];
vector<int> adj[Max], topo;
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

    dfs(1);

    reverse(topo.begin(), topo.end());

    memset(dis, -0x3f, sizeof(dis));
    dis[1] = 1;
    for (int n : topo)
    {
        if (dis[n] < 0)
            continue;
        for (int v : adj[n])
        {
            if (dis[v] < dis[n] + 1)
            {
                dis[v] = dis[n] + 1;
                par[v] = n;
            }
        }
    }

    if (dis[N] < 0)
        cout << "IMPOSSIBLE\n";
    else
    {
        vector<int> ans;
        cout << dis[N] << '\n';
        for (int v = N; v != 0; v = par[v])
            ans.push_back(v);
        reverse(ans.begin(), ans.end());
        for (int v : ans)
            cout << v << ' ';
    }

    return 0;
}