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

bool e(int i, int j) { return i >= 0 && i < N && j >= 0 && j < N; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> grid[i];

    pii mid_pnt = {-1, -1};
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            int n_connects = 0;
            for (int k = 0; k < 4; ++k)
            {
                int x = i + dx[k], y = j + dy[k];
                if (e(x, y) && grid[x][y] == '*')
                    n_connects++;
            }
            if (n_connects == 3)
                mid_pnt = make_pair(i, j);
        }

    cout << mid_pnt.first << ' ' << mid_pnt.second;
    return 0;
}
