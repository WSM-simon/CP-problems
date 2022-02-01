#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pli pair<long long, int>
#define f first
#define s second

using namespace std;

const int Max = 1e5 + 3;
const ll inf = 1e18 + 7;

ll N, M, dis[Max];
vector<pli> adj[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1].push_back({w, v2});
    }

    fill(dis, dis + Max, inf);
    dis[1] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        pli n = pq.top();
        pq.pop();
        if (dis[n.s] != n.f)
            continue;
        for (pli v : adj[n.s])
        {
            if (dis[n.s] + v.f < dis[v.s])
            {
                dis[v.s] = dis[n.s] + v.f;
                pq.push({dis[v.s], v.s});
            }
        }
    }
    for (int i = 1; i <= N; ++i)
        cout << dis[i] << " \n"[i == N];
    return 0;
}
