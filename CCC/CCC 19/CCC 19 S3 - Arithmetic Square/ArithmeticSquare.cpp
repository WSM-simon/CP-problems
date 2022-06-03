#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long, long long>

using namespace std;

const int MxN = 4;
const int inf = 1e18;

ll grid[MxN][MxN], ver[MxN], hor[MxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(begin(grid), end(grid), inf);
    for (int i = 1; i < MxN; ++i) {
        for (int j = 1; j < MxN; ++j) {
            int tem;
            cin >> tem;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                continue;
            }
            ver[i]++, hor[j], grid[i][j] = tem;
        }
    }

    return 0;
}
