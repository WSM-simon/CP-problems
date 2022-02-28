#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define f first
#define s second
#define ar3 array<int 3>

using namespace std;

const int Max = 1e5 + 3;
const int inf = 0x3f3f3f3f;

int N, M;
ll res = 0;
vector<pll> adj[Max];
bool vis[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
        
    }

    // memset(dis, 0x3f, sizeof(dis));
    int edge=0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    while (edge<N)
    {
        if (pq.empty())
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        pll n = pq.top();
        pq.pop();
        if (vis[n.s])
            continue;
        res += n.f;
        vis[n.s] = 1;
        ++edge;
        for (pll v : adj[n.s])
            pq.push(v);
    }
    cout << res << '\n';
    return 0;
}
