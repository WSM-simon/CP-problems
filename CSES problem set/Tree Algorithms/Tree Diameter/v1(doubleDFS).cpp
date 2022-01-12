#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 2e5 + 3;
int N, c, dis[Max];
vector<int> adj[Max];

void dfs(int n, int p)
{
    for (int v : adj[n])
    {
        if (v != p)
        {
            dis[v] = dis[n] + 1;
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

    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    dfs(1, 0);
    dis[c] = 0;
    dfs(c, 0);
    cout << dis[c] << '\n';
    return 0;
}