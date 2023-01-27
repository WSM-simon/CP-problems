#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ar3 array<ll, 3>
#define f first
#define s second

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

ll N, Q, e[MxN];
map<pll, ll> res;
vector<pll> queries, q_cpy;
vector<ar3> edges;

ll find(ll x) {
    return (e[x] < 0 ? x : e[x] = find(e[x]));
}
bool unite(ll x, ll y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    if (x > y) swap(x, y);
    e[x] += e[y], e[y] = x;
    return 1;
}
ll count_x(ll x) {
    return -e[find(x)];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("mootube.in");
    ofstream fout("mootube.out");
    memset(e, -1, sizeof(e));

    fin >> N >> Q;
    for (int i = 0; i < N - 1; ++i) {
        ll p, q, r;
        fin >> p >> q >> r;
        edges.push_back({p, q, r});
    }
    for (int i = 0; i < Q; ++i) {
        ll k, v;
        fin >> k >> v;
        queries.push_back({k, v});
    }
    q_cpy = queries;
    sort(queries.begin(), queries.end(), [](pll x, pll y) { return x.first > y.first; });
    sort(edges.begin(), edges.end(), [](ar3 x, ar3 y) { return x[2] > y[2]; });

    int i = 0;
    for (auto [k, v] : queries) {
        for (; i < N - 1 && edges[i][2] >= k; ++i) {
            unite(edges[i][0], edges[i][1]);
        }
        res[{k, v}] = count_x(v) - 1;
    }
    for (pll p : q_cpy) {
        fout << res[p] << '\n';
    }
    return 0;
}
