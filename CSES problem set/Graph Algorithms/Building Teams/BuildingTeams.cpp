#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e5 + 2;
int n, m, color[Max];
vector<int> adj[Max];

void dfs(int k, int c = 0)
{
    if (~color[k])
    {
        if (color[k] ^ c)
        {
            cout << "IMPOSSIBLE";
            exit(0);
        }
        return;
    }
    color[k] = c;
    for (int v : adj[k])
        dfs(v, c ^ 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int tem1, tem2;
        cin >> tem1 >> tem2;
        adj[tem1].push_back(tem2);
        adj[tem2].push_back(tem1);
    }

    memset(color, -1, 4 * (n + 1));

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
            dfs(i);
    }

    for (int i = 1; i <= n; i++)
        cout << color[i] + 1 << ' ';

    return 0;
}