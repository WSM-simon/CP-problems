#include <bits/stdc++.h>
#define ll long long
#define ar3 array<long long, 3>
#define pll pair<long long, long long>
#define f first
#define s second

using namespace std;

const int MxN = 2e3 + 3;
const int MxM = 1e5 + 3;
const ll INF = 1e18 + 7;

ll N, M, e[MxN], dis[MxN];
struct edge {
    ll u, v, l, c;
};
struct sedge {
    ll v, l, c;
};
vector<edge> edges;
vector<sedge> graph[MxN];

ll find(int x) {
    return (e[x] < 0 ? x : e[x] = find(e[x]));
}

bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y], e[y] = x;
    return 1;
}

bool comp(const edge e1, const edge e2) {
    return e1.l < e2.l;
}

ll dijkstra(ll x, ll y) {
    fill(dis, dis + MxN, INF);
    dis[x] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, x});
    while (!pq.empty()) {
        pll n = pq.top();
        pq.pop();
        if (dis[n.s] != n.f)
            continue;
        for (sedge v : graph[n.s]) {
            if (dis[n.s] + v.l < dis[v.v]) {
                dis[v.v] = dis[n.s] + v.l;
                pq.push({dis[v.v], v.v});
            }
        }
    }
    return dis[y];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(e, -1, sizeof(e));
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        ll u, v, l, c;
        cin >> u >> v >> l >> c;
        edges.push_back({u, v, l, c});
    }

    ll res = 0;
    sort(edges.begin(), edges.end(), comp);
    for (edge k : edges) {
        if (unite(k.u, k.v)) {
            res += k.c;
            graph[k.u].push_back({k.v, k.l, k.c});
            graph[k.v].push_back({k.u, k.l, k.c});
        } else {
            if (k.l < dijkstra(k.u, k.v)) {
                res += k.c;
                graph[k.u].push_back({k.v, k.l, k.c});
                graph[k.v].push_back({k.u, k.l, k.c});
            }
        }
    }
    cout << res << '\n';
    return 0;
}
