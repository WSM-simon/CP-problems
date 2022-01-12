#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

const int Max = 1e3 + 3;
int N, M, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char step[4] = {'D', 'R', 'U', 'L'};
char graph[Max][max];

bool isValid(int x, int y) { return graph[x][y] != '#' && x >= 0 && x < N && y >= 0 && y < M; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<pii> q;
    pii st, ed;

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            char tem;
            cin >> tem;
            graph[i][j] = tem;
            if (tem == 'A')
                st = { i,
                       j } if (tem == "M")
                         q.push({i, j});
        }
    // input over

    while (!q.empty())
    {
        pii n = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k)
        {
            int x = n.f + dx[k], y = n.s + dy[k];
            if (isValid(x, y))
            {
                graph[n.f][n.s] = '#';
                q.push({x, y});
            }
        }
    }

    q.push(st);
    while (!q.empty())
    {
        pii n = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k)
        {
            int x = n.f + dx[k], y = n.s + dy[k];
            if (isValid(x, y))
            {
                graph[x][y] = '#';
                q.push({x, y});
            }
        }
    }
    return 0;
}