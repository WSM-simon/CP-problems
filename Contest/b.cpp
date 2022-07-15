#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MxN = 2e5 + 3;
const ll MxM = 2e5 + 3;

ll N, Q, preQ1[MxN], preQ2[MxN];
vector<ll> q1, q2;

ll foo(ll x, ll l, ll r) {
    return abs((preQ1[x] - preQ1[l]) - (preQ2[x] - preQ2[r + 1]));
}

ll tripartition(ll l, ll r) {
    ll l2 = l, r2 = r;
    while (l2 < r2 - 2) {
        ll mid = (l2 + r2) / 2;
        ll mmid = (mid + r2) / 2;
        if (foo(mid, l, r) > foo(mmid, l, r))
            l2 = mid;
        else
            r2 = mmid;
    }
    
    if (foo(l2, l, r) < foo(l2 + 1, l, r))
        if (foo(l2, l, r) < foo(l2 + 2, l, r))
            return l2;
    else if (foo(l2 + 1, l, r) < foo(l2, l, r))
        if (foo(l2 + 1, l, r) < foo(l2 + 2, l, r))
            return l2 + 1;
    else if (foo(l2 + 2, l, r) < foo(l2 + 1, l, r))
        if (foo(l2 + 2, l, r) < foo(l2, l, r))
            return l2 + 2;
}

void solve(ll l, ll r) {
    ll ans = tripartition(l, r);
    cout << max(preQ1[ans] - preQ1[l], preQ2[ans] - preQ2[r + 1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    for (ll i = 0; i < N; ++i) {
        ll tem;
        cin >> tem;
        q1.push_back(tem);
    }
    for (ll i = 0; i < N; ++i) {
        ll tem;
        cin >> tem;
        q2.push_back(tem);
    }

    for (ll i = 0; i < N; ++i)
        preQ1[i + 1] = preQ1[i] + q1[i];
    preQ2[N - 1] = q2[N - 1];
    for (ll i = N - 2; i >= 0; --i)
        preQ2[i] = preQ2[i + 1] + q2[i];

    for (ll i = 0; i < Q; ++i) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        solve(l, r);
    }
    return 0;
}