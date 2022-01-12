#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e2 + 3;

int T, N, M, col[Max], d1[Max], dN[Max];
vector<int> adj[Max], nodes1, nodesN;

void dfs(int n, int c)
{
    for (int v : adj[n])
    {
        if (!col[v])
        {
            col[v] = c;
            if (c == 1)
                nodes1.push_back(v);
            if (c == N)
                nodesN.push_back(v);
            dfs(v, c);
        }
    }
}

void solve()
{
    cin >> N >> M;
    memset(d1, 0x3f, sizeof(d1));
    memset(dN, 0x3f, sizeof(dN));
    memset(col, 0, sizeof(col));
    nodes1.clear(), nodesN.clear();
    for (int i = 0; i < Max; ++i)
        adj[i].clear();

    for (int i = 0; i < M; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    nodes1.push_back(1), nodesN.push_back(N);
    col[1] = 1, col[N] = N;
    dfs(1, 1), dfs(N, N);
    for (int i = 2; i < N; ++i)
        if (!col[i])
        {
            col[i] = i;
            dfs(i, i);
        }

    sort(nodes1.begin(), nodes1.end());
    sort(nodesN.begin(), nodesN.end());
    for (int i = 0; i < nodes1.size(); ++i)
    {
        for (int j = i - 1, cnt = 1; j > 0; j--, cnt++)
        {
            if (j != 0)
                if (j == nodes1[i - 1])
                    break;
            d1[col[j]] = min(d1[col[j]], cnt);
        }
        for (int j = i + 1, cnt = 1; j <= N; j++, cnt++)
        {
            if (j != nodesN.size() - 1)
                if (j == nodes1[i + 1])
                    break;
            d1[col[j]] = min(d1[col[j]], cnt);
        }
    }
    int node;
    for (int i = 2; i < N; ++i)
    {
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}