#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 1e4;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    ll a, b, ans = 0;
    
    cin >> a;
    while (cin >> c >> b) {
        if (c == '+')
            ans = (ans + a) % MOD, a = b;
        else if (c == '*')
            a = ((a % MOD) * (b % MOD)) % MOD;
    }
    ans = (ans + a) % MOD;

    cout << ans << '\n';
    return 0;
}