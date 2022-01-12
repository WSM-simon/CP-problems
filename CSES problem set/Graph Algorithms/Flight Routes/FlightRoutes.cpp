#include <bits/stdc++.h>
#define ll long long
#define pli pair<ll, int>
#define f first
#define s second

using namespace std;

const ll inf = 1e18;
const int Max = 1e5 + 3;
int N, M, K;
vector<vector<ll>> dis;
vector<pli> graph[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    dis.resize(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int e1, e2, w;
        cin >> e1 >> e2 >> w;
        graph[e1].push_back({w, e2});
    }

    for (int i = 0; i <= N; ++i)
    {
        dis[i].resize(K);
        for (int j = 0; j < K; ++j)
            dis[i][j] = inf;
    }

    dis[1][0] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        pli n = pq.top();
        pq.pop();
        if (dis[n.s][K - 1] < n.f)
            continue;

        for (pli v : graph[n.s])
            if (dis[v.s][K - 1] > n.f + v.f)
            {
                dis[v.s][K - 1] = n.f + v.f;
                pq.push({dis[v.s][K - 1], v.s});
                sort(dis[v.s].begin(), dis[v.s].end());
            }
    }

    for (int i = 0; i < K; ++i)
        cout << dis[N][i] << ' ';
    return 0;
}