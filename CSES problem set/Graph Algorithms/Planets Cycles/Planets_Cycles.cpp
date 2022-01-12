#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 2e5 + 3;
int N, sccCnt = 0, id = 1, to[Max], to2[Max], ids[Max], low[Max], scc[Max], dis[Max]; // to2 is for scc
bool onStack[Max], vis[Max];
stack<int> stk;

void tarjan(int n)
{
    ids[n] = low[n] = id++;
    stk.push(n);
    onStack[n] = 1;

    int v = to[n];
    if (!ids[v])
        tarjan(v);
    if (onStack[v])
        low[n] = min(low[n], low[v]);
    if (ids[n] == low[n])
    {
        int nodesCnt = 0; // Count the number of nodes in each scc. If there is a cycle, then this cnt will be greater than 1, and vice versa.
        sccCnt++;
        while (true)
        {
            int u = stk.top();
            stk.pop();
            onStack[u] = 0;
            nodesCnt++;
            low[u] = ids[n];
            scc[u] = sccCnt;
            if (n == u)
                break;
        }
        dis[sccCnt] = nodesCnt;
    }
}

void newMap()
{
    for (int i = 1; i <= N; ++i)
    {
        int v = to[i];
        if (scc[i] != scc[v])
            to2[scc[i]] = scc[v];
    }
}

// this topo is searching the scc graph.
void topo(int n)
{
    vis[n] = 1;
    int v = to2[n];
    if (v == 0)
        return;
    if (!vis[v])
        dfs(v);
    dis[n] += dis[v];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> to[i];

    for (int i = 1; i <= N; ++i)
        if (!ids[i])
            tarjan(i);

    newMap();
    for (int i = 1; i <= sccCnt; ++i)
    {
        // i here refer to scc
        if (!vis[i])
            dfs(i);
    }
    
    for (int i = 1; i <= N; ++i)
        cout << dis[scc[i]] << ' ';

    return 0;
}