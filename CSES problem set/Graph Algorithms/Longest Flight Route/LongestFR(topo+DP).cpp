#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int inf = 0x3f3f3f3f;
const int Max = 1e5 + 3;
int N, M, inD[Max], dis[Max], par[Max];
vector<int> adj[Max];
queue<int> q;

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
    dis[1] = 0;
    for (int i = 1; i <= N; ++i)
        if (inD[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int v : adj[node])
        {
            if (dis[v] < dis[node] + 1)
            {
                dis[v] = dis[node] + 1;
                par[v] = node;
            }
            if (--inD[v] == 0)
                q.push(v);
        }
    }

    if (dis[N] < 0)
        cout << "IMPOSSIBLE";
    else
    {
        vector<int> ans;
        ans.push_back(N);
        for (int n2 = par[N]; n2 != 1; n2 = par[n2])
            ans.push_back(n2);
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int v : ans)
            cout << v << ' ';
    }

    return 0;
}