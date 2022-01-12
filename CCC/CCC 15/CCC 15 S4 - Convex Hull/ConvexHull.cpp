#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define ar3 array<int, 3>
#define f first
#define s second

using namespace std;

const int inf = 0x3f3f3f3f;
int K, N, M, dis[2003][203];
vector<ar3> graph[2003];
// time, CMs of wear out, islands.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K >> N >> M;
    for (int i = 1; i <= M; ++i)
    {
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        graph[a].push_back({t, h, b});
        graph[b].push_back({t, h, a});
        // time, wear out, island
    }

    int st, ed;
    cin >> st >> ed;
    memset(dis, 0x3f, sizeof(dis));
    memset(dis[st], 0, sizeof(dis[st]));

    priority_queue<ar3, vector<ar3>, greater<ar3>> pq;
    // dis, wear out, island
    pq.push({0, 0, st});

    while (!pq.empty())
    {
        ar3 node = pq.top();
        pq.pop();
        if (dis[node[2]][node[1]] > node[0])
            continue;
        // visited
        for (ar3 v : graph[node[2]])
            if (node[1] + v[1] < K)
                if (dis[v[2]][node[1] + v[1]] > node[0] + v[0])
                {
                    dis[v[2]][node[1] + v[1]] = node[0] + v[0];
                    pq.push({node[0] + v[0], node[1] + v[1], v[2]});
                }
    }

    int ans = *min_element(dis[ed], dis[ed] + 203);
    cout << (ans == inf ? -1 : ans);

    return 0;
}