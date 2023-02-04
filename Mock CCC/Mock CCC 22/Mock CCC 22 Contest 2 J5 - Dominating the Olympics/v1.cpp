#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M, cost[MxN], col[MxN];
vector<int> graph[MxN];

// fals;kdjfl;as
bool dfs(int n) {
    col[n] = 1;
    for (int v : graph[n]) {
        if (col[v] == 1) {
            cost[n] = 0;
            col[n] = 3;
            return false;
        }
        if (col[v] == 0) {
            if (!dfs(v)) {
                cost[n] = 0;
                col[n] = 3;
                return false;
            }
            else{
                cost[n] += cost[v];
                cost[v] = 0;
            }
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
        for (int j = 0; i < R; ++j) {
            int n;
            cin >> n;
            graph[i].push_back(n);
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (col[i] == 0) {
            if (!dfs(i))
                cost[i] = 0;
        }
    }

    return 0;
}
