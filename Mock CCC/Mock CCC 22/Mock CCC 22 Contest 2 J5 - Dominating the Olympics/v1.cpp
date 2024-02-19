#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e2 + 3;
const int MxM = 1e5 + 3;

int N, M, cost[MxN], col[MxN], dp[MxN], inD[MxN];
vector<int> graph_reverse[MxN];
queue<int> q;

bool dfs(int n) {
    for (int v : graph_reverse[n]) {
        if (col[v] == 0)
            continue;
        if (col[v] == 1) {
            dfs(v);
            dp[n] = max(dp[n], dp[v]);
        }
        if (col[v] == 2)
            dp[n] = max(dp[n], dp[v]);
    }
    dp[n] += cost[n];
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
        inD[i] = R;
        if (R == 0) q.push(i);
        for (int j = 0; j < R; ++j) {
            int node;
            cin >> node;
            graph_reverse[node].push_back(i);
        }
    }
    // find cycle
    while (!q.empty()) {
        int n = q.front();
        col[n] = 1;
        q.pop();
        for (int v : graph_reverse[n]) {
            if (--inD[v] == 0)
                q.push(v);
        }
    }
    // 0 mean in the cycle, 1 means not in cycle, 2 means visited
    for (int i = 1; i <= N; ++i) {
        if (col[i] == 1)
            dfs(i);
    }
    cout << *max_element(dp, end(dp)) << '\n';
    return 0;
}
