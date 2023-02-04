#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;
const ll INF = 1e18 + 3;

int N, M;
map<char, ll> mp1, mp2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        mp1[c]++;
    }
    for (int i = 0; i < M; ++i) {
        char c;
        cin >> c;
        mp2[c]++;
    }

    ll mx = 0, mn = INF, res = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
        mx = max(mp1[c], mx);
        if (mp2[c] != 0) mn = min(mp1[c], mn);
        res += mp1[c] * mp2[c];
    }
    if (mx > mn)
        res = res + mx - mn;
    cout << res << '\n';
    return 0;
}