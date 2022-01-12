#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
int N, M, par[Max], found = 0;
vector<int> adj[Max];
bool vis[Max];

bool dfs(int n, int pre)
{
    vis[n] = 1;
    for (int v : adj[n])
    {
        if (v == pre)
            continue;
        par[v] = n;
        if (vis[v])
        {
            found = v;
            return 0;
        }
        if (!dfs(v, n))
            return 0;
    }
    return 1;
}

void retrace(int n)
{
    vector<int> ans;
    ans.push_back(n);
    for (int v = par[n]; v != n; v = par[v])
        ans.push_back(v);
    ans.push_back(n);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int v : ans)
        cout << v << ' ';
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

    for (int i = 1; i <= N; ++i)
    {
        if (!vis[i])
        {
            if (!dfs(i, 0))
            {
                break;
            }
        }
    }

    if (!found)
        cout << "IMPOSSIBLE";
    else
        retrace(found);

    return 0;
}