#include <bits/stdc++.h>

using namespace std;

const int MxN = 5e4 + 3;

int N, K, cnt = 0, e[4 * MxN];

int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y], e[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    memset(e, -1, sizeof(e));
    for (int i = 0; i < K; ++i) {
        int c, x, y;
        cin >> c >> x >> y;
        if (x > N || y > N)
            cnt++;
        else if (c == 1) {
            if (find(x) == find(y + N) || find(y) == find(x + N)) cnt++;
            else unite(x, y), unite(x + N, y + N), unite(x + 2 * N, y + 2 * N);
        } else if (c == 2) {
            if (find(x) == find(y) || find(y) == find(x + N)) cnt++;
            else unite(x, y + N), unite(x + N, y + 2 * N), unite(x + 2 * N, y);
        }
    }
    
    cout << cnt;
    return 0;
}