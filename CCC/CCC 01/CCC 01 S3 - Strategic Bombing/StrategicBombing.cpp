#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

const int Max = 27;
vector<int> adj[Max];
vector<pii> edges;
bool vis[Max];
pii banned;

bool isvalid(int a, int v) { return !vis[v] && !(a == banned.f && v == banned.s) && !(a == banned.s && v == banned.f); }

bool dfs(int n, int ed)
{
    vis[n] = 1;
    if (n == ed)
        return 1;

    for (int v : adj[n])
        if (isvalid(n, v))
            if (dfs(v, ed))
                return 1;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char v1, v2;
    cin >> v1 >> v2;
    while (v1 != '*')
    {
        int a = v1 - 'A', b = v2 - 'A';
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back({a, b});
        cin >> v1 >> v2;
    }

    vector<pii> ans;
    for (pii e : edges)
    {
        memset(vis, 0, sizeof(vis));
        banned = e;
        if (!dfs(0, 1))
            ans.push_back(e);
    }

    for (pii p : ans)
        cout << (char)(p.f + 'A') << (char)(p.s + 'A') << '\n';
    cout << "There are " << ans.size() << " disconnecting roads.\n";

    return 0;
}