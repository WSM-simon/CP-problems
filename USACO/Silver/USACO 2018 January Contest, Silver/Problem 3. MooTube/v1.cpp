#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int MxN = 1e5 + 3;

int N, M;
vector<pii> graph[MxN];

int find_n_q(int n, int k, int pre = -1) {
    int res = 1;
    for (auto [nxt, val] : graph[n]) {
        if (nxt == pre)
            continue;
        if (val >= k) {
            res += find_n_q(nxt, k, n);
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("mootube.in");
    ofstream fout("mootube.out");

    fin >> N >> M;
    for (int i = 0; i < N - 1; ++i) {
        int m, n, v;
        fin >> m >> n >> v;
        graph[m].push_back({n, v});
        graph[n].push_back({m, v});
    }
    for (int i = 0; i < M; ++i) {
        int v, n;
        fin >> v >> n;
        fout << find_n_q(n, v) - 1 << '\n';
    }
    return 0;
}