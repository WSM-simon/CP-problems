#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
int N, M, vis[Max], par[Max];
vector<int> adj[Max];

void dfs(int n, int prev = -1)
{
    vis[n] = 1;
    par[n] = prev;
    for (int v : adj[n])
    {
        if (vis[v] == 0)
            dfs(v, n);
        else if (vis[v] == 1)
        {
            vector<int> ans;
            ans.push_back(v);
            for (int n2 = n; n2 != v; n2 = par[n2])
                ans.push_back(n2);
            ans.push_back(v);

            cout << ans.size() << '\n';
            reverse(ans.begin(), ans.end());
            for (int i : ans)
                cout << i << ' ';

            exit(0);
        }
    }
    vis[n] = 2;
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
        if (!vis[i])
            dfs(i);

    cout << "IMPOSSIBLE";
    return 0;
}