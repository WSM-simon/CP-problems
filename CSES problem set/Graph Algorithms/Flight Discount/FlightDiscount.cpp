#include <bits/stdc++.h>
#define ll long long
#define pli pair<long long, int>
#define f first
#define s second

using namespace std;

const ll INF = 1e18;
const int Max = 1e5 + 3;
ll dis1[Max], disN[Max];
vector<pli> in[Max], out[Max];

void dijkstra(int st, ll dis[], vector<pli> graph[])
{
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, st});
    while (!pq.empty())
    {
        pli n = pq.top();
        pq.pop();
        if (dis[n.s] != n.f)
            continue;

        for (pli v : graph[n.s])
        {
            if (dis[v.s] > v.f + n.f)
            {
                dis[v.s] = v.f + n.f;
                pq.push({dis[v.s], v.s});
            }
        }
    }
}

int N, M;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int t1, t2, w;
        cin >> t1 >> t2 >> w;
        in[t2].push_back({w, t1});
        out[t1].push_back({w, t2});
    }

    fill(dis1, dis1 + Max, INF);
    fill(disN, disN + Max, INF);
    dis1[1] = 0, disN[N] = 0;

    dijkstra(1, dis1, out);
    dijkstra(N, disN, in);

    ll cost = INF;
    for (int i = 1; i <= N; ++i)
    {
        for (pli v : out[i])
        {
            int j = v.s;
            ll w = v.f;
            cost = min(cost, dis1[i] + disN[j] + w / 2);
        }
    }

    cout << cost;
    return 0;
}