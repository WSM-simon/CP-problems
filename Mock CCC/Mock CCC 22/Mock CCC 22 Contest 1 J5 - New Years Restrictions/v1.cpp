#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int MxN = 20;
const int MxM = 1e5 + 3;

int N, M;
vector<pii> restricts;
bool restrictions[MxN][MxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        restrictions[a][b] = 1;
        restrictions[b][a] = 1;
    }

    int res = 0;
    bool error = 0;
    for (int i = 0; i < (1 << N); ++i) {
        error = 0;
        for (int j = 0; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                if ((i >> j) & 1 && (i >> k) & 1 && restrictions[j + 1][k + 1]) {
                    error = 1;
                    break;
                }
                if (error) break;
            }
            if (error) break;
        }
        if (error) continue;
        res = max(res, __builtin_popcount(i));
    }
    cout << res << '\n';
    return 0;
}