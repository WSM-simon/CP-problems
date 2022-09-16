#include <bits/stdc++.h>
#define ll long long
#define ar3 array<ll, 3>

using namespace std;

const int MxN = 1e6 + 7;
const ll INF = 1e18 + 7;
const int MOD1 = 1e6 + 3;
const int MOD2 = 239;
const int MOD3 = 17;

int e[MxN];
ar3 s[MxN], _inf = {INF, INF, INF};

int find(ll x) {
    return e[x] < 0 ? x : e[x] = find(e[x]);
}

ll my_hash(ar3 arr) {
    ll hsh1 = (arr[0] * MOD2 + MOD3) % MOD1;
    ll hsh2 = (arr[1] * MOD2 + MOD3) % MOD1;
    ll hsh3 = (arr[2] * MOD2 + MOD3) % MOD1;
    ll hsh = (hsh1 + hsh2 + hsh3)%MOD1;
    if (hsh < 0)
        hsh *= -1 * MOD3;
    hsh %= MOD1;
    if (s[hsh] == _inf) {
        s[hsh] = arr;
        return hsh;
    } else if (s[hsh] == arr)
        return hsh;
    else {
        while (true) {
            if (hsh < MOD1)
                hsh++;
            else
                hsh = 0;

            if (s[hsh] == _inf) {
                s[hsh] = arr;
                return hsh;
            } else if (s[hsh] == arr)
                return hsh;
        }
    }
}

bool unite(ar3 a, ar3 b) {
    int x = find(my_hash(a)), y = find(my_hash(b));
    if (x == y) return 0;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y], e[y] = x;
    return 1;
}

ll SQdistance(ar3 x, ar3 y) {
    return (x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1]) + (x[2] - y[2]) * (x[2] - y[2]);
}

void solve() {
    ll n, h, r;
    cin >> n >> h >> r;
    vector<ar3> holes, lower, upper;
    memset(e, -1, sizeof(e));
    fill(s, s + MxN, _inf);
    for (int i = 0; i < n; ++i) {
        ll x, y, z;
        cin >> x >> y >> z;
        ar3 h1 = {x, y, z};
        for (ar3 h2 : holes)
            if (SQdistance(h1, h2) <= 4 * r * r)
                unite(h1, h2);
        holes.push_back(h1);
        if (z <= r) lower.push_back(h1);
        if (z + r >= h) upper.push_back(h1);
    }
    // holes on lower surface and upper surface
    for (ar3 l : lower)
        for (ar3 u : upper)
            if (find(my_hash(l)) == find(my_hash(u))) {
                cout << "Yes" << '\n';
                return;
            }
    cout << "No" << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    while (N--)
        solve();

    return 0;
}