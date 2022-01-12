#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define ar3 array<int, 3>

using namespace std;

const ll INF = 1e18;
const int Max = 2503;
ll dis[Max];
vector<ar3> e;
vector<int> in[Max], out[Max];
int N, M;
bool vis1[Max], vis2[Max];

void dfs1(int n)
{
    if (vis1[n])
        return;
    vis1[n] = 1;
    for (int v : out[n])
        dfs1(v);
}

void dfs2(int n)
{
    if (vis2[n])
        return;
    vis2[n] = 1;
    for (int v : in[n])
        dfs2(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        e.push_back({t1, t2, t3});
        in[t2].push_back(t1);
        out[t1].push_back(t2);
    }

    fill(dis, dis + Max, -INF);
    dis[1] = 0;

    int flag;
    vector<int> cycle;
    for (int i = 0; i < N; ++i)
    {
        flag = 0;
        for (ar3 v : e)
        {
            if (dis[v[1]] < dis[v[0]] + v[2])
            {
                dis[v[1]] = dis[v[0]] + v[2];
                flag = v[1];
                if (i >= N - 1)
                    cycle.push_back(v[1]);
            }
        }
        if (!flag)
            break;
    }

    if (flag)
    {

        dfs1(1), dfs2(N);
        for (int v : cycle)
        {
            if (vis1[v] && vis2[v])
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << dis[N];

    return 0;
}