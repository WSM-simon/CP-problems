#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second

using namespace std;

const int MxN = 1e3 + 3;
const int MxM = 1e5 + 3;

int N, M;
bool vis[MxN];
pair<int, int> croco[MxN];
vector<int> graph[MxN];
// 0 is the island, N+1 is the land;

bool dfs(int n) {
    if (n == N + 1)
        return true;
    for (int v : graph[n]) {
        if (!vis[v]) {
            vis[v] = 1;
            if (dfs(v))
                return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        croco[i].f = a, croco[i].s = b;
    }
    for (int i = 0; i < N; ++i) {
        int a = croco[i].f, b = croco[i].s;
        // sqr(a^2+b^2) -7.5 <= M
        if (4 * (a * a + b * b) <= 4 * M * M + 225 + 60 * M) {
            graph[0].push_back(i + 1);
            graph[i + 1].push_back(0);
        }
    }
    for (int i = 0; i < N; ++i) {
        int a = croco[i].f, b = croco[i].s;
        if (abs(a - 50) <= M || abs(b - 50) <= M || abs(a + 50) <= M || abs(b + 50) <= M) {
            graph[N + 1].push_back(i + 1);
            graph[i + 1].push_back(N + 1);
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int a1 = croco[i].f, b1 = croco[i].s;
            int a2 = croco[j].f, b2 = croco[j].s;
            if ((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2) <= M * M) {
                graph[i + 1].push_back(j + 1);
                graph[j + 1].push_back(i + 1);
            }
        }
    }
    vis[0] = 1;
    if (dfs(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
