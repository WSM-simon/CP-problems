#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

ll N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (ll n = 1; n <= N; ++n)
        cout << n * n * (n * n - 1) / 2 - 4 * (n - 1) * (n - 2) << '\n';
    return 0;
}