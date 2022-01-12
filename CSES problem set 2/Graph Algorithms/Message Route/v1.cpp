#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
int N, M, par[Max];
vector<int> adj[Max];
bool vis[Max];

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

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        if (n == N)
            break;

        for (int v : adj[n])
        {
            if (!vis[v])
            {
                q.push(v);
                vis[v] = 1;
                par[v] = n;
            }
        }
    }

    if (vis[N] == 1)
    {
        vector<int> ans;
        for (int v = N; v != 0; v = par[v])
            ans.push_back(v);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int v : ans)
            cout << v << ' ';
    }
    else
        cout << "IMPOSSIBLE";

    return 0;
}