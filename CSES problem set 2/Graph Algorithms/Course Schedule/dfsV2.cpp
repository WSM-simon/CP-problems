#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
int N, M, col[Max];
vector<int> adj[Max], topo;

bool dfs(int n)
{
    col[n] = 1;
    for (int v : adj[n])
    {
        if (col[v] == 1)
            return 0;
        if (col[v] == 2)
            continue;
        if (!dfs(v))
            return 0;
    }
    col[n] = 2;
    topo.push_back(n);

    return 1;
}

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
    }

    int ok = 1;
    for (int i = 1; i <= N; ++i)
    {
        if (!col[i])
            if (!dfs(i))
            {
                ok = 0;
                break;
            }
    }

    reverse(topo.begin(), topo.end());
    if (ok)
        for (int v : topo)
            cout << v << ' ';
    else
        cout << "IMPOSSIBLE";

    return 0;
}