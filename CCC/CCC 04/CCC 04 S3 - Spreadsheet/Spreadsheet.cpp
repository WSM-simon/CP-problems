#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

const int Max = 13;
ll R = 10, C = 9, graph[Max][Max];
bool vis[Max][Max];
map<pii, vector<pii>> sumCells;

int dfs(int i, int j)
{
    vis[i][j] = 1;
    int sum = 0;
    bool found;
    for (pii p : sumCells[{i, j}])
    {
        found = 0;
        int x = p.f, y = p.s;
        if (graph[x][y] != -1)
        {
            sum += graph[x][y];
            found = 1;
            continue;
        }
        else if (!vis[x][y])
        {
            int add = dfs(x, y);
            if (add != -1)
            {
                found = 1;
                sum += add;
            }
        }
        if (!found)
        {
            graph[x][y] = -1;
            return -1;
        }
    }
    graph[i][j] = sum;
    return sum;
}

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
