#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define f first
#define s second
#define ar3 array<int, 3>

using namespace std;

const int MxN = 1e5 + 3;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int N, M;
string grid[21];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

pii find_first_star()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (grid[i][j] == '*')
                return make_pair(i, j);
    return make_pair(-1, -1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> grid[i];

    pii first_star = find_first_star();
    if (first_star.first == -1)
    {
        cout << "N" << '\n';
        return 1;
    }
    int ver_cnt = 0;
    for (int i = first_star.second; i < N; ++i)
    {
        if (grid[first_star.first][i] == '*')
            ver_cnt++;
    }
    if (ver_cnt % 2 == 0 || ver_cnt < 3)
    {
        cout << "N" << '\n';
        return 1;
    }
    int mid = first_star.second + ver_cnt / 2;

    int hor_cnt = 0;
    for (int j = first_star.first + 1; j < N; ++j)
    {
        if (grid[j][mid] == '*')
        {
            hor_cnt++;
        }
    }
    if (ver_cnt == hor_cnt)
        cout << "Y\n";
    else
        cout << "N\n";
    return 0;
}
