#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

const int inf = 0x3f3f3f3f;
const int Max = 1e5 + 3;
ll N, M, par[Max], dis[Max];
vector<int> adj[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("C:\\Users\\Simian\\OneDrive\\myCode\\CSES problem set\\Graph Algorithms\\Longest Flight Route\\case_15.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    par[1] = -1;
    while (!pq.empty())
    {
        pii node = pq.top();
        pq.pop();
        if (node.f > dis[node.s])
            continue;

        for (int v : adj[node.s])
            if (dis[v] > dis[node.s] - 1)
            {
                dis[v] = dis[node.s] - 1;
                par[v] = node.s;
                pq.push({dis[v], v});
            }
    }

    if (par[N] == 0)
        cout << "IMPOSSIBLE";
    else
    {
        vector<int> ans;
        ans.push_back(N);
        for (int v = par[N]; v != -1; v = par[v])
            ans.push_back(v);
        reverse(ans.begin(), ans.end());

        cout << ans.size() << '\n';
        for (int v : ans)
            cout << v << ' ';
    }
    return 0;
}