#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxS = 19;

int N, M, lg2[MxN] = {0, 0, 1};
ll st[MxN][MxS];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    // pre calculation
    // for (int i = 3; i <= MxN; ++i) lg2[i] = lg2[i / 2] + 1;
    for (int i = 1; i <= N; ++i) cin >> st[i][0];
    for (int j = 1; j <= MxS; ++j)
        for (int i = 1; i + (1 << j) - 1 <= N; ++i)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

    // read queries
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        // int s = lg2[y - x + 1];
        int s = __lg(y-x+1);
        cout << min(st[x][s], st[y - (1 << s) + 1][s]) << '\n';
    }
    return 0;
}