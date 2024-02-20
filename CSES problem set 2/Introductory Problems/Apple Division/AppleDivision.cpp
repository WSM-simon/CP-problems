#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

ll N, M;
ll arr[30];

ll solve(ll n, ll s1, ll s2) {
    if (n == N+1)
        return abs(s1 - s2);
    return min(solve(n + 1, s1 + arr[n], s2), solve(n + 1, s1, s2 + arr[n]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i + 1];
    cout << solve(1, 0, 0) << '\n';
    return 0;
}
