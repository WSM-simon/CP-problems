#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int Max = 53;
int N, K, T, cnt = 0;
char grid[Max][Max];

bool isValid(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == '.'; }

void dfs(int x, int y, int m, int k)
{
    if (x == N - 1 && y == N - 1)
    {
        cnt++;
        return;
    }

    if (m == 0)
    {
        if (isValid(x + 1, y))
            dfs(x + 1, y, 1, k);
        if (isValid(x, y + 1))
            dfs(x, y + 1, 2, k);
    }
    if (m == 1)
    {
        if (isValid(x + 1, y))
            dfs(x + 1, y, 1, k);
        if (isValid(x, y + 1))
            if (k - 1 >= 0)
                dfs(x, y + 1, 2, k - 1);
    }
    if (m == 2)
    {
        if (isValid(x + 1, y))
            if (k - 1 >= 0)
                dfs(x + 1, y, 1, k - 1);
        if (isValid(x, y + 1))
            dfs(x, y + 1, 2, k);
    }
}

void solve()
{
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j];

    // 1 means turn right, 2 means turn down, starts with 0.
    cnt = 0;
    dfs(0, 0, 0, K);
    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();
    return 0;
}