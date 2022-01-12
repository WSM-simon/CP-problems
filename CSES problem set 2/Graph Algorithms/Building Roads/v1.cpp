#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
int N, M;
bool vis[Max];
vector<int> adj[Max];

void dfs(int n)
{
    vis[n] = 1;
    for (int v : adj[n])
        if (!vis[v])
            dfs(v);
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

    vector<int> ans;
    for (int i = 1; i <= N; ++i)
        if (!vis[i])
        {
            dfs(i);
            ans.push_back(i);
        }

    int sz = ans.size();
    cout << sz - 1 << '\n';
    for (int i = 0; i < sz - 1; ++i)
        cout << ans[i] << ' ' << ans[i + 1] << '\n';

    return 0;
}