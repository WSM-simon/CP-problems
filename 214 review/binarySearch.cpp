#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 5e4 + 3;
const int MxM = 1e5 + 3;

int L, N, M, stones[MxN];

bool check(int k) {
    int cnt_M = 0;
    int p1 = 0, p2 = 1;
    while (p2 < N + 1) {
        p2++;
        if (stones[p2] - stones[p1] >= k) {
            cnt_M += p2 - p1 - 1;
            p1 = p2;
        }
    }
    if (stones[p2] - stones[p1] < k)
        cnt_M += p2 - p1 - 1;
    if (cnt_M > M)
        return 0;
    else
        return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> N >> M;
    stones[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> stones[i];
    }
    stones[N + 1] = L;
    int p = 0;
    for (int i = L; i >= 1; i /= 2) {
        while (check(p + i)) {
            p += i;
        }
    }
    cout << p << '\n';
    return 0;
}
