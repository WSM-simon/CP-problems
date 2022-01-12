#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;

int N, M, c, nodeCnt = 0, diaCnt = 0, nei[Max], dis[Max], par[Max];
bool isPho[Max];
vector<int> adj[Max];

void dfs(int n, int p)
{
    for (int v : adj[n])
    {
        if (v != p && nei[v] != 0)
        {
            dis[v] = dis[n] + 1;
            par[v] = n;
            if (dis[v] > dis[c])
                c = v;
            dfs(v, n);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int v;
        cin >> v;
        isPho[v] = 1;
    }

    for (int i = 0; i < N - 1; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        nei[v1]++, nei[v2]++;
    }

    //pruning
    queue<int> q;

    for (int i = 0; i < N; ++i)
        if (nei[i] == 1 && !isPho[i])
            q.push(i);

    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        for (int v : adj[n])
        {
            if (!nei[v])
                continue;
            nei[n]--, nei[v]--;
            if (nei[v] == 1 && !isPho[v])
                q.push(v);
        }
    }

    // nodeCnt is the number of nodes from the prunned tree.
    for (int i = 0; i < N; ++i)
        if (nei[i] != 0)
            nodeCnt++;

    // find the diameter of the tree
    for (int i = 0; i < N; ++i)
    {
        if (nei[i] != 0)
        {
            dis[i] = 0, par[i] = -1;
            dfs(i, -1);
            break;
        }
    }

    dis[c] = 0, par[c] = -1;
    dfs(c, -1);
    for (int v = c; v != -1; v = par[v])
        diaCnt++;

    // the fomula to find the minimum length.
    cout << 2 * (nodeCnt - 1) - diaCnt + 1;
    return 0;
}