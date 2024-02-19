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
    for (int i = 0; i < N; ++i) {
        ll a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        if (a > 2 * b)
            cout << "NO\n";
        else if ((2 * b - a) % 3 != 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}