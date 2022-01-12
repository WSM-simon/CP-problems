#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 1e3 + 3;
int N, M, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char graph[Max][Max];

bool isvalid(int i, int j) { return i >= 0 && i < N && j >= 0 && j < M && graph[i][j] != '#'; }

void dfs(int i, int j)
{
    graph[i][j] = '#';
    for (int k = 0; k < 4; ++k)
        if (isvalid(i + dx[k], j + dy[k]))
            dfs(i + dx[k], j + dy[k]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> graph[i][j];

    int cnt = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (graph[i][j] != '#')
            {
                dfs(i, j);
                cnt++;
            }

    cout << cnt;
    return 0;
}