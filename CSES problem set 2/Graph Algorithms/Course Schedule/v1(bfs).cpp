#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 3;
int N, M, inD[Max];
vector<int> adj[Max], topo;

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
        ++inD[v2];
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i)
        if (!inD[i])
            q.push(i);

    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        topo.push_back(n);
        for (int v : adj[n])
            if (--inD[v] == 0)
                q.push(v);
    }
    
    if (topo.size() != N)
        cout << "IMPOSSIBLE";
    else
        for (int v : topo)
            cout << v << ' ';

    return 0;
}