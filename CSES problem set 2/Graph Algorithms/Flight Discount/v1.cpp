#include <bits/stdc++.h>
#include <queue>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

const int inf = 0x3f3f3f3f;
const int Max = 1e2 + 3;
int N, M, inDis[Max], outDis[Max];
vector<pii> inAdj[Max], outAdj[Max];

void dijkstra(int dis[], vector<pii> adj[], int st)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});
    while (!pq.empty())
    {
        pii n = pq.top();
        pq.pop();

        if (dis[n.s] < n.f)
            continue;
        for (pii v:adj[n.s])
        {
            if (dis[v.s] < n.f + v.f)
            {
                dis[v.s] = n.f+v.f;
                pq.push({dis[v.s], v.s});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        outAdj[v1].push_back({w, v2});
        inAdj[v2].push_back({w, v1});
    }
    memset(outDis, 0x3f, sizeof(outDis));
    memset(inDis, 0x3f, sizeof(inDis));
    outDis[1] = 0;
    inDis[N] = 0;

    dijkstra(outDis, outAdj, 1);
    dijkstra(inDis, inAdj, N);

    int cost=inf;
    for (int i=1; i<=N; ++i)
        for (pii v:outAdj[i])
            cost = min(cost, outDis[i] + inDis[v.s] - v.f/2);
    
    cout << cost;

    return 0;
}