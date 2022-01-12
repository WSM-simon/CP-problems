#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

const int Max = 13;
int R = 10, C = 9, graph[Max][Max];
int topo[Max][Max];
map<pii, vector<pii>> sumCells;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
        {
            string s;
            cin >> s;
            if (s[0] >= 65)
            {
                graph[i][j] = -1;
                int sz = s.size(), cnt = 0;
                while (cnt < sz)
                {
                    sumCells[{i, j}].push_back({s[cnt] - 'A' + 1, s[cnt + 1] - '0'});
                    ++topo[i][j]
                    cnt += 3;
                }
            }
            else
                graph[i][j] = stoi(s);
        }

    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
            if (graph[i][j] == -1)
                if (!vis[i][j])
                    dfs(i, j);

    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            if (graph[i][j] == -1)
                cout << '*' << ' ';
            else
                cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}