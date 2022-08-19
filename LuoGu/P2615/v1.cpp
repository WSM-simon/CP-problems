#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<vector<int>> grid(N + 5, vector<int>(N + 5, 0));
    vector<pair<int, int>> pos((N + 1) * (N + 1));
    grid[1][N / 2 + 1] = 1;
    pos[1] = {1, N / 2 + 1};
    for (int i = 2; i <= N * N; ++i) {
        int k = i-1;
        if (pos[k].f == 1 && pos[k].s != N)
            grid[N][pos[k].s + 1] = i, pos[i] = {N, pos[k].s + 1};
        else if (pos[k].s == N && pos[k].f != 1)
            grid[pos[k].f - 1][1] = i, pos[i] = {pos[k].f - 1, 1};
        else if (pos[k].f == 1 && pos[k].s == N)
            grid[2][N] = i, pos[i] = {2, N};
        else if (grid[pos[k].f - 1][pos[k].s + 1] == 0)
            grid[pos[k].f - 1][pos[k].s + 1] = i, pos[i] = {pos[k].f - 1, pos[k].s + 1};
        else
            grid[pos[k].f + 1][pos[k].s] = i, pos[i] = {pos[k].f + 1, pos[k].s};
    }
    for (int i=1;i<=N; i++)
        for (int j=1;j<=N;++j)
            cout << grid[i][j] << " \n"[j==N];
    return 0;
}