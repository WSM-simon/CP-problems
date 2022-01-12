#include <bits/stdc++.h>
#define ll long long
#define pil pair<int, ll>
#define f first
#define s second

using namespace std;

const int Max = 1e5 + 3;

int N, M, sccCnt = 0, id = 1, coins1[Max], low[Max], ids[Max], scc[Max], inD[Max];
ll coins2[Max], dis[Max], d = 0;
bool onStack[Max];
stack<int> stk;
vector<int> adj[Max], adj2[Max]; // adj2 store SCCs as nodes.

void tarjan(int n)
{
    ids[n] = low[n] = id++;
    stk.push(n);
    onStack[n] = 1;

    for (int v : adj[n])
    {
        if (!ids[v])
            tarjan(v);
        if (onStack[v])
            low[n] = min(low[n], low[v]);
    }

    if (ids[n] == low[n])
    {
        sccCnt++;
        while (true)
        {
            int node = stk.top();
            stk.pop();
            onStack[node] = 0;
            low[node] = ids[n];
            scc[node] = sccCnt;
            // coins2 is the coin number of each scc
            coins2[sccCnt] += coins1[node];
            if (node == n)
                break;
        }
    }
}

void newMap()
{
    for (int i = 1; i <= N; ++i)
        for (int v : adj[i])
            if (scc[i] != scc[v])
            {
                adj2[scc[i]].push_back(scc[v]);
                inD[scc[v]]++; // Counting indegrees, this is for topo sorting.
            }
}

void topo()
{
    memset(dis, 0, sizeof(dis));
    queue<int> q;
    for (int i = 1; i <= sccCnt; ++i)
    {
        // i here is scc
        if (inD[i] == 0)
        {
            q.push(i);
            dis[i] = coins2[i];
        }
    }

    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        for (int v : adj2[n])
        {
            if (dis[v] < dis[n] + coins2[v])
            {
                dis[v] = dis[n] + coins2[v];
                if (d < dis[v])
                    d = dis[v];
            }
            if (--inD[v] == 0)
                q.push(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> coins1[i];

    for (int i = 0; i < M; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
    }

    for (int i = 1; i <= N; ++i)
        if (!ids[i])
            tarjan(i);

    newMap();
    topo();
    cout << d;

    return 0;
}