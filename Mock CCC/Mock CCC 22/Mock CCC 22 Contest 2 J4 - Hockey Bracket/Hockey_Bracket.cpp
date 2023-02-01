#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 2e3 + 3;

int N, S, topo[Max];
vector<int> graph[Max], adj[Max], topov;
bool vis[Max];

void dfs(int n)
{
    for (int v : adj[n])
    {
        if (!vis[v])
        {
            vis[v] = 1;
            dfs(v);
        }
    }
    topov.push_back(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < (N / S); ++i)
    {
        for (int j = 0; j < S; ++j)
        {
            int t;
            cin >> t;
            graph[i].push_back(t);
        }
    }
    fill(topo, topo + Max, 1);
    for (int i = 0; i < ((S - 1) * N / 2); ++i)
    {
        int v1, v2;
        char k;
        cin >> v1 >> v2 >> k;
        if (k == 'W')
            adj[v2].push_back(v1);
        if (k == 'L')
            adj[v1].push_back(v2);
        if (k == 'T')
        {
            if (v1 < v2)
                adj[v2].push_back(v1);
            else
                adj[v1].push_back(v2);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < (N / S); ++i)
    {
        topov.clear();
        for (int j : graph[i])
            if (!vis[j])
                vis[j] = 1, dfs(j);
        cout << topov[q - 1] << ' ';
    }
    cout << '\n';
    return 0;
}
