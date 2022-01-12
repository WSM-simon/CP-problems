#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 30;
int W, r, c, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char graph[Max][Max];
vector<int> rooms;
int currSpace = 0;

bool isvalid(int x, int y) { return (graph[x][y] == '.' && 1 <= x && x <= r && 1 <= y && y <= c); }

bool comp(const int x, const int y) { return (x > y); }

void dfs(int i, int j)
{
    if (graph[i][j] != '.')
        return;
    graph[i][j] = 'I';
    ++currSpace;
    for (int k = 0; k < 4; ++k)
        if (isvalid(i + dx[k], j + dy[k]))
            dfs(i + dx[k], j + dy[k]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> W >> r >> c;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> graph[i][j];

    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            if (graph[i][j] == '.')
            {
                currSpace = 0;
                dfs(i, j);
                rooms.push_back(currSpace);
            }

    sort(rooms.begin(), rooms.end(), comp);
    int cnt = 0;
    for (int room : rooms)
        if (W >= room)
            W -= room, ++cnt;
        else
            break;
    if (cnt != 1)
        cout << cnt << " rooms, " << W << " square metre(s) left over";
    else
        cout << cnt << " room, " << W << " square metre(s) left over";
    return 0;
}