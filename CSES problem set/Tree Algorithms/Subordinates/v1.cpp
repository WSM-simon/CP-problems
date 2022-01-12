#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 2e5 + 3;
int N, cnt[Max];
vector<int> adj[Max];

void dfs(int s, int e)
{
    cnt[s] = 1;
    for (int u : adj[s])
    {
        if (u != e)
        {
            dfs(u, s);
            cnt[s] += cnt[u];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 2; i <= N; ++i)
    {
        int v;
        cin >> v;
        adj[v].push_back(i);
        adj[i].push_back(v);
    }

    dfs(1, 0);

    for (int i = 1; i <= N; ++i)
        cout << cnt[i] - 1 << ' ';

    return 0;
}