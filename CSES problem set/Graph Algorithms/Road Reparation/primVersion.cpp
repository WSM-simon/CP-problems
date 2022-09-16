#include <bits/stdc++.h>
#define ll long long
#define pli pair<ll, int>
#define f first
#define s second

using namespace std;

const ll inf = 1e18;
const int Max = 1e5 + 3;
int N, M;
bool vis[Max];
vector<pli> graph[Max];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int e1, e2, w;
        cin >> e1 >> e2 >> w;
        graph[e1].push_back({w, e2});
        graph[e2].push_back({w, e1});
    }

    ll weight = 0;
    int edges = 0;
    // priority_queue<pli, vector<pli>, greater<pli>> pq;
    set<pli> pq;
    pq.insert({0, 1});

    for (int i = 0; i < N; ++i) {
        if (pq.empty()) {
            cout << "IMPOSSIBLE";
            return 0;
        }

        pli node = *pq.begin();
        pq.erase(pq.begin());

        vis[node.s] = 1;
        weight += node.f;
        for (pli v : graph[node.s])
            if (!vis[v.s])
                pq.insert(v);
    }

    cout << weight;
    return 0;
}