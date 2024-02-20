#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

ll N, M, K;
ll a[MxN], b[MxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt = 0;
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    for (int i = 0; i < M; ++i)
        cin >> b[i];
    sort(a, a + N);
    sort(b, b + M);
    for (int i = 0, j = 0; i < N && j < M; ++i) {
        if (a[i] + K < b[j])
            continue;
        while (a[i] - K > b[j] && j < M)
            j++;
        if (a[i] + K >= b[j] && a[i] - K <= b[j])
            cnt++, j++;
    }
    cout << cnt;
    return 0;
}
