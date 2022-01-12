#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

const int Max = 23;
int r, c, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool vis[Max][Max];
char graph[Max][Max];

bool isvaild(int x, int y) { return (!vis[x][y] && graph[x][y] != '*' && 1 <= x && x <= r && 1 <= y && y <= c); }

void bfs(int i, int j)
{
    queue<pii> q;
    q.push({1, 1});
    int layer = 0;
    while (!q.empty())
    {
        int qsize = q.size();
        ++layer;
        while (qsize--)
        {
            pii node = q.front();
            q.pop();
            tie(i, j) = node;

            if (i == r && j == c)
            {
                cout << layer << '\n';
                return;
            }
            
            if (graph[i][j] == '+')
            {
                for (int k = 0; k < 4; ++k)
                    if (isvaild(i + dx[k], j + dy[k]))
                    {
                        vis[i + dx[k]][j + dy[k]] = 1;
                        q.push({i + dx[k], j + dy[k]});
                    }
            }

            else if (graph[i][j] == '-')
            {
                for (int k = 0; k < 4; ++k)
                    if (isvaild(i, j + dy[k]))
                    {
                        vis[i][j + dy[k]] = 1;
                        q.push({i, j + dy[k]});
                    }
            }

            else if (graph[i][j] == '|')
            {
                for (int k = 0; k < 4; ++k)
                    if (isvaild(i + dx[k], j))
                    {
                        vis[i + dx[k]][j] = 1;
                        q.push({i + dx[k], j});
                    }
            }
        }
    }
    cout << -1 << '\n';
}

void solve()
{
    cin >> r >> c;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> graph[i][j];
    memset(vis, 0, sizeof(vis));
    bfs(1, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}