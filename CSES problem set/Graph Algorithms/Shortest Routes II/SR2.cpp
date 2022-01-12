#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
 
using namespace std;
 
const ll inf = 1e18;
const int Max = 503;
ll N, M, Q, dis[Max][Max];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> N >> M >> Q;
    fill(dis[0], dis[0] + Max * Max, inf);
 
    for (int i = 1; i <= N; ++i)
        dis[i][i] = 0;
 
    for (int i = 0; i < M; ++i)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if (t3 < dis[t1][t2])
            dis[t1][t2] = dis[t2][t1] = t3;
    }
 
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = i + 1; j <= N; ++j)
                if (dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
 
    for (int i = 0; i < Q; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2;
        cout << (dis[t1][t2] >= inf ? -1 : dis[t1][t2]) << '\n';
    }
    return 0;
}