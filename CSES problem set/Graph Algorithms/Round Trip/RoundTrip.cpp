#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
int n, m, parent[Max];
bool vis[Max];
vector<int> adj[Max];

void dfs(int i, int p = -1)
{
    parent[i] = p;
    vis[i] = 1;
    for (int a : adj[i])
        if (!vis[a])
            dfs(a, i);
        else
        {
            if (a == p)
                continue;

            parent[a] = i;
            stack<int> ans;
            ans.push(a);

            int a2 = parent[a];
            while (a2 != a)
            {
                ans.push(a2);
                a2 = parent[a2];
            }
            ans.push(a);

            cout << ans.size() << '\n';
            while (!ans.empty())
            {
                cout << ans.top() << ' ';
                ans.pop();
            }
            exit(0);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);

    cout << "IMPOSSIBLE";
    return 0;
}