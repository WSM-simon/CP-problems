#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll c, m , K;
    cin >> c >> m >> K;
    if (c < m) swap(c, m);
    cout << c*K << '\n';
    return 0;
}
