#include <bits/stdc++.h>
#define ll long long
#define ar3 array<int, 3>

using namespace std;

const int MxN = 1e3 + 3;
const int MxM = 1e5 + 3;

int N, M, e[MxN], blocks;
vector<ar3> rebuild;

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

    for (int i = 0; i < MxN; ++i) e[i] = -1;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        rebuild.push_back({x, y, t});
    }
    sort(rebuild.begin(), rebuild.end(), [](const ar3 &a, const ar3 &b) { return a[2] < b[2]; });

    for (ar3 arr : rebuild) {
        if (unite(arr[0], arr[1])) {
            if (--N == 1) {
                cout << arr[2] << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}