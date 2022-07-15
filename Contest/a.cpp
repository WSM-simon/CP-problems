#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 3e3 + 3;
const int MxM = 3e3 + 3;

int N, M, cnt = 0, preR[MxN][MxM], preC[MxN][MxM];
char grid[MxN][MxM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> grid[i][j];

    // prefix
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            preR[i][j] = preR[i][j - 1] + (grid[i][j] == '*');
            preC[i][j] = preC[i - 1][j] + (grid[i][j] == '*');
        }

    // counting
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (grid[i][j] != '*') {
                // row
                if (preR[i][j] >= 2) {
                    cnt++;
                    cout << i << ' ' << j << '\n';
                } else if (preR[i][M] - preR[i][j] >= 2) {
                    cnt++;
                    cout << i << ' ' << j << '\n';
                // column
                } else if (preC[i][j] >= 2) {
                    cnt++;
                    cout << i << ' ' << j << '\n';
                } else if (preC[N][j] - preC[i][j] >= 2) {
                    cnt++;
                    cout << i << ' ' << j << '\n';
                }
            }
    cout << cnt << '\n';
    return 0;
}