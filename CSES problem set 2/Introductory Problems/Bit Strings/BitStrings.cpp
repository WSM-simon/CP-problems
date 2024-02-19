#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;
const int Mod = 1e9 + 7;

ll N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    ll ans = 1;
    while (N--)
        ans = (ans * 2) % Mod;
    cout << ans << '\n';
    return 0;
}