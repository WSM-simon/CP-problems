#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
const int inf = 0x3f3f3f3f;

int N, M, inD[Max], par[Max], dis[Max];
vector<int> adj[Max];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        ++inD[v2];
    }

    memset(dis, -0x3f, sizeof(dis));
    dis[1]=0;;
    
    queue<int> q;
    for (int i = 1; i <= N; ++i)
        if (inD[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        for (int v : adj[n])
        {
            if (dis[v] < dis[n] + 1)
            {
                dis[v] = dis[n] + 1;
                par[v] = n;
            }
            if (--inD[v] == 0)
                q.push(v);
        }
    }
    if (dis[N] < 0)
        cout << "IMPOSSIBLE\n";
    else
    {
        cout << dis[N] + 1 << '\n';
        vector<int> topo;
        for (int v = N; v != 0; v = par[v])
            topo.push_back(v);
        reverse(topo.begin(), topo.end());
        for (int v : topo)
            cout << v << ' ';
    }

    return 0;
}