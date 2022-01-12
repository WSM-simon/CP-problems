#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 2e5 + 3;

int N, d = 0, leaf[Max];
vector<int> adj[Max];

void dfs(int n, int p = -1)
{
    for (int v : adj[n])
    {
        if (v == p)
            continue;
        dfs(v, n);
        d = max(d, leaf[n] + 1 + leaf[v]);
        leaf[n] = max(leaf[n], leaf[v] + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    dfs(1);
    cout << d;
    return 0;
}