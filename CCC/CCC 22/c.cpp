#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define ar4 array<int, 4>
#define f first
#define s second

using namespace std;

const int Max = 1503;
const int inf = 0x3f3f3f3f;

int N, M, K;
// down, right, up, left
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int graph[Max][Max], dis[Max][Max];
bool vis[Max][Max];

// i, j, dis, col
queue<ar4> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int col;
            cin >> col;
            if (col == 0)
            {
                graph[i][j] = inf;
                dis[i][j] = inf;
            }
            else
            {
                graph[i][j] = col;
                dis[i][j] = 0;
                q.push({i, j, 1, col});
            }
        }
    }
    while (!q.empty())
    {
        ar4 n = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int x = n[0] + dx[i], y = n[1] + dy[i];
            if (x < 0 || x >= N || y < 0 || y >= M)
                continue;

            int col = graph[x][y], d = dis[x][y];
            if (d > n[2])
            {
                graph[x][y] = n[3];
                dis[x][y] = n[2];
                if (n[2] + 1 <= K)
                    q.push({x, y, n[2] + 1, n[3]});
            }
            if (d == n[2])
            {
                // comparing the col now
                if (col > n[3])
                {
                    graph[x][y] = n[3];
                    // dis[x][y] = n[2];
                    if (n[2] + 1 <= K)
                        q.push({x, y, n[2] + 1, n[3]});
                }
                else
                    continue;
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << (graph[i][j] == inf ? 0 : graph[i][j]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
