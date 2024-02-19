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
        ll x, y, ans = 0;

        cin >> y >> x;
        ll mx = max(x, y);
        ans += (mx - 1) * (mx - 1);

        if (mx % 2 == 1) {
            ans += x;
            if (x == mx)
                ans += x - y;
        } else {
            ans += y;
            if (y == mx) {
                ans += y - x;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}