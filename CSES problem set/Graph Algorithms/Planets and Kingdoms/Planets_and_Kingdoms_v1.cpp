#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;

int N, M, id = 1, scccnt = 0, low[Max], ids[Max], scc[Max];
vector<int> adj[Max];
bool onStack[Max];
stack<int> stk;

void tarjan(int n)
{
    stk.push(n);
    onStack[n] = 1;
    ids[n] = low[n] = id++;

    for (int v : adj[n])
    {
        if (ids[v] == 0)
            tarjan(v);
        if (onStack[v])
            low[n] = min(low[n], low[v]);
    }

    if (ids[n] == low[n])
    {
        scccnt++;
        while (true)
        {
            int node = stk.top();
            stk.pop();
            onStack[node] = 0;
            low[node] = ids[n];
            scc[node] = scccnt;
            if (node == n)
                break;
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
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
    }

    for (int i = 1; i <= N; ++i)
        if (ids[i] == 0)
            tarjan(i);

    // output
    cout << scccnt << '\n';
    for (int i = 1; i <= N; ++i)
        cout << scc[i] << ' ';

    return 0;
}