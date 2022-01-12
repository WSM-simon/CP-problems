#include <bits/stdc++.h>

using namespace std;

const int N = 10000 + 10;
int n, c, d[N];
vector<int> E[N];

void dfs(int u, int fa)
{
    for (int v : E[u])
    {
        if (v == fa)
            continue;
        d[v] = d[u] + 1;
        if (d[v] > d[c])
            c = v;
        dfs(v, u);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1, 0);
    d[c] = 0, dfs(c, 0);
    cout << d[c];

    return 0;
}