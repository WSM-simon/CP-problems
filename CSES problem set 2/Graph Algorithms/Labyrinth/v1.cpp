#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

const int Max = 1e3 + 3;
int N, M, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, par[Max][Max];
char graph[Max][Max], moves[4] = {'D', 'R', 'U', 'L'};

bool isValid(int i, int j) { return i >= 0 && i < N && j >= 0 && j < M && graph[i][j] != '#'; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pii st, ed;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            char c;
            cin >> c;
            if (c == 'A')
                st = {i, j};
            if (c == 'B')
                ed = {i, j};
            graph[i][j] = c;
        }
    }

    queue<pii> q;
    q.push(st);
    graph[st.f][st.s] = '#';
    while (!q.empty())
    {
        pii node = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k)
        {
            int nx = node.f + dx[k], ny = node.s + dy[k];
            if (isValid(nx, ny))
            {
                graph[nx][ny] = '#';
                // visited
                q.push({nx, ny});
                par[nx][ny] = k;
            }
        }
    }
    if (graph[ed.f][ed.s] != '#')
        cout << "NO";
    else
    {
        cout << "YES\n";
        vector<int> ans;
        int a = ed.f, b = ed.s;
        while (a != st.f || b != st.s)
        {
            int p = par[a][b];
            ans.push_back(p);
            a -= dx[p], b -= dy[p];
        }
        cout << ans.size() << '\n';
        reverse(ans.begin(), ans.end());
        for (int i : ans)
            cout << moves[i];
    }
    return 0;
}