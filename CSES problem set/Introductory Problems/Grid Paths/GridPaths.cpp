#include <bits/stdc++.h>
#define ll long long
#define pic pair<int, char>
#define pii pair<int, int>

using namespace std;

string path;
bool vis[7][7];
int ways = 0;

bool isvaild(int x, int y)
{
    return (!vis[x][y] && x >= 0 && x <= 6 && y >= 0 && y <= 6);
}

void dfs(int n, int x, int y)
{
    // cout << n << ' ' << x << ' ' << y << '\n';

    if (x == 0 && y == 6)
    {
        if (n == 48)
            ways++;
        return;
    }

    vis[x][y] = 1;
    if (path[n] == '?' || path[n] == 'L')
    {
        if (isvaild(x - 1, y))
            if (!(!isvaild(x - 2, y) && isvaild(x - 1, y + 1) && isvaild(x - 1, y - 1)))
                dfs(n + 1, x - 1, y);
    }
    if (path[n] == '?' || path[n] == 'R')
    {
        if (isvaild(x + 1, y))
            if (!(!isvaild(x + 2, y) && isvaild(x + 1, y + 1) && isvaild(x + 1, y - 1)))
                dfs(n + 1, x + 1, y);
    }
    if (path[n] == '?' || path[n] == 'U')
    {
        if (isvaild(x, y - 1))
            if (!(!isvaild(x, y - 2) && isvaild(x - 1, y - 1) && isvaild(x + 1, y - 1)))
                dfs(n + 1, x, y - 1);
    }
    if (path[n] == '?' || path[n] == 'D')
    {
        if (isvaild(x, y + 1))
            if (!(!isvaild(x, y + 2) && isvaild(x + 1, y + 1) && isvaild(x - 1, y + 1)))
                dfs(n + 1, x, y + 1);
    }
    vis[x][y] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> path;
    dfs(0, 0, 0);
    cout << ways;
    return 0;
}