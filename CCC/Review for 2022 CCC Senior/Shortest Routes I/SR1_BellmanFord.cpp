#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
const ll inf = 1e18 + 9;

struct edge
{
    int u, v;
    ll w;
};

int N, M;
ll dis[Max];
vector<edge> e;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({u, v, w});
    }
    fill(dis, dis + Max, inf);
    dis[1] = 0;
    for (int i = 0; i < N - 1; ++i)
        for (int j = 0; j < M; ++j)
            dis[e[j].v] = min(dis[e[j].v], dis[e[j].u] + e[j].w);

    for (int i = 1; i <= N; ++i)
        cout << dis[i] << ' ';
    
    
    return 0;
}
