#include <bits/stdc++.h>
#define ll long long
#define ar3 array<int, 3>

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M, e[MxN], res[MxM];
vector<ar3> videos, queries;

int find(int x) {
    return e[x] < 0 ? x : e[x] = find(e[x]);
}

bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y], e[y] = x;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N - 1; ++i) {
        int p, q, r;
        cin >> p >> q >> r;
        videos.push_back({p, q, r});
    }
    for (int i = 0; i < M; ++i) {
        int k, v;
        cin >> k >> v;
        queries.emplace_back(k, v, i);
    }

    sort(videos.begin(), videos.end(), [](const ar3 a, const ar3 b) { return a[2] > b[2]; });
    sort(queries.begin(), queries.end(), [](const ar3 a, const ar3 b) { return a[0] > b[0]; });

    int i = 0;
    memset(e, -1, sizeof(e));
    for (auto [k, v, q] : queries) {
        for (; videos[i][2] >= k && i < videos.size(); ++i)
            unite(videos[i][0], videos[i][1]);
        res[q] = -1 * e[find(v)] - 1;
    }

    for (int i = 0; i < M; ++i)
        cout << res[i] << '\n';

    return 0;
}