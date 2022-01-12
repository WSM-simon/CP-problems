#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5+3;
int N, M;
vector<int> adj[Max], topo;
short col[Max];

bool dfs(int n)
{
    col[n]=1;
    for (int v:adj[n])
    {
        if (col[v] == 1)
            return false;
        else if (col[v] == 0)
            if (!dfs(v))
                return false;
    }
    col[n]=2;
    topo.push_back(n);
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for (int i=0; i<M; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
    }
    for (int i=1; i<=N; ++i)
        if (col[i] == 0)
            if (!dfs(i))
            {
                cout << "IMPOSSIBLE" << '\n';
                return 0;
            }
    
    reverse(topo.begin(), topo.end());
    for (int i:topo)
        cout << i << ' ';
    return 0;
}