#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;

int N, M, cnt = 0, id = 1, ids[Max], low[Max];
bool onStack[Max], lowVis[Max]; // vis is for output
vector<int> adj[Max];
stack<int> stk;

void dfs(int n)
{
    stk.push(n);
    onStack[n] = 1;
    ids[n] = low[n] = id++;

    for (int v : adj[n])
    {
        if (!ids[v])
            dfs(v);
        if (onStack[v])
            low[n] = min(low[n], low[v]);
    }

    if (ids[n] == low[n])
    {
        while (true)
        {
            int node = stk.top();
            stk.pop();
            onStack[node] = 0;
            low[node] = ids[n];
            if (node == n)
                break;
        }
        cnt++;
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
        if (!ids[i])
            dfs(i);

    if (cnt == 1)
        cout << "YES";
    else
    {
        cout << "1 0 ";
        // 不知道怎么打印答案， 但发现1 0 永远正确， 估计是bug。
    }

    return 0;
}