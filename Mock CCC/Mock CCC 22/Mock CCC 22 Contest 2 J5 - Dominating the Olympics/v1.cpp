#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M, cost[MxN], col[MxN];
vector<int> graph[MxN];

bool dfs(int n) {
    col[n] = 1;
    for (int v : graph[n]) {
        if (col[v] == 0) {
            if (!dfs(v)) {
                col[n] = 3;
                return false;
            }
        }
        if (col[v] == 1) {
            col[n] = 3;
            return false;
        }
    }
    col[n] = 2;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int T, R;
        cin >> T >> R;
        cost[i] = T;
        for (int j = 0; j < R; ++j) {
            int node;
            cin >> node;
            graph[i].push_back(node);
        }
    }
    // 0 mean unvisited, 1 means visiting, 2 means visted, 3 means dead end
    for (int i = 1; i <= N; ++i) {
        if (col[i] == 0)
            dfs(i);
    }
    int res = 0;
    for (int i = 1; i <= N; ++i) {
        if (col[i] != 3)
            res += cost[i];
    }
    cout << res << '\n';
    return 0;
}
