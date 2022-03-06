#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 4;
int N, M, vis[Max];
vector<int> adj[Max];

bool dfs(int n)
{
    for (int v : adj[n])
    {
        if (vis[v] == -1)
        {
            vis[v] = vis[n] ^ 1;
            if (!dfs(v))
                return 0;
        }
        else if (vis[v] != vis[n] ^ 1)
            return 0;
    }
    return 1;
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
        adj[v2].push_back(v1);
    }

    bool found = 1;
    memset(vis, -1, sizeof(vis));
    for (int i = 1; i <= N; ++i)
    {
        if (vis[i] == -1)
        {
            vis[i] = 1;
            if (!dfs(i))
            {
                found = 0;
                break;
            }
        }
    }

    if (found)
        for (int i = 1; i <= N; ++i)
            cout << (vis[i] == 1 ? 1 : 2) << ' ';
    else
        cout << "IMPOSSIBLE";
    return 0;
}