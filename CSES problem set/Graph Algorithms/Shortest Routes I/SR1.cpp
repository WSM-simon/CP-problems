#include <bits/stdc++.h>
#define ll long long
#define pli pair<ll, int>
#define f first
#define s second

using namespace std;

const int Max = 1e5 + 3;
const int inf = 0x3f3f3f3f;

ll N, M, dis[Max];
vector<pli> adj[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        pli node = pq.top();
        pq.pop();
        if (node.f != dis[node.s])
            continue;
        for (pli v : adj[node.s])
        {
            if (dis[v.s] > dis[node.s] + v.f)
            {
                dis[v.s] = dis[node.s] + v.f;
                pq.push({dis[v.s], v.s});
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << dis[i] << ' ';

    return 0;
}