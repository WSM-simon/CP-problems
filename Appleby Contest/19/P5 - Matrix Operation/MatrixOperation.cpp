#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define mem_dfs(x, y) (mem[x][y] ? mem[x][y] : mem[x][y] = dfs(x, y))
char _;

using namespace std;

const int MxN = 1503;
const int inf = 1e9 + 3;

int N, grid[MxN][MxN], mem[MxN][MxN];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool e(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N;}

int dfs(int x, int y)
{
    int ans = 0;
    for (int k = 0; k < 4; ++k)
        if (e(x + dx[k], y + dy[k]) && grid[x + dx[k]][y + dy[k]] > grid[x][y])
            ans = max(ans, mem_dfs(x + dx[k], y + dy[k]) + 1);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    su(N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            su(grid[i][j]);

    int ans = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            ans = max(ans, mem_dfs(i, j));

    cout << ans << '\n';
    return 0;
}
