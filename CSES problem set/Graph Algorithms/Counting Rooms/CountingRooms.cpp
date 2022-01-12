#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m;
char graph[1001][1001];

void dfs(int i, int j)
{
    graph[i][j] = '#';

    if (graph[i + 1][j] == '.')
        dfs(i + 1, j);
    if (graph[i - 1][j] == '.')
        dfs(i - 1, j);
    if (graph[i][j + 1] == '.')
        dfs(i, j + 1);
    if (graph[i][j - 1] == '.')
        dfs(i, j - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> graph[i][j];

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (graph[i][j] == '.')
                dfs(i, j), cnt++;

    cout << cnt;
    return 0;
}