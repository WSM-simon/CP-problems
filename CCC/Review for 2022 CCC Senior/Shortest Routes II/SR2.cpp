#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 503;
const ll inf = 1e18 + 3;

ll N, M, Q, dis[Max][Max], a[90];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> Q;
    fill(dis[0], dis[0]+Max*Max, inf);
    for (int i = 1; i <= N; ++i)
        dis[i][i] = 0;
    for (int i = 0; i < M; ++i)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        dis[v][u] = dis[u][v] = min(dis[u][v], w);
    }
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = i + 1; j <= N; ++j)
                if (dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];

    for (int i = 0; i < Q; ++i)
    {
        int u, v;
        cin >> u >> v;
        cout << (dis[u][v] == inf ? -1 : dis[u][v]) << '\n';
    }
    return 0;
}
