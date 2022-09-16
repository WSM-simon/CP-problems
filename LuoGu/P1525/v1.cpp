#include <bits/stdc++.h>
#define ll long long
#define ar3 array<int, 3>

using namespace std;

const int MxN = 4e4 + 3;

int N, M, e[MxN];

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

    memset(e, -1, sizeof(e));
    vector<ar3> v;

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
    sort(v.begin(), v.end(), [](const ar3 a, const ar3 b) { return a[2] > b[2]; });
    for (ar3 p : v) {
        if (find(p[0]) == find(p[1])) {
            cout << p[2] << '\n';
            return 0;
        }
        unite(p[0] + N, p[1]);
        unite(p[0], p[1] + N);
    }
    
    cout << 0 << '\n';
    return 0;
}