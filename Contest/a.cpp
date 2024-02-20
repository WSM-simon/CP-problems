#include <bits/stdc++.h>
#define ll long long
#define ar3 array<long long, 3>

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;
const ll INF = 1e18 + 7;

ll N, M, l1[MxN], l2[MxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> l1[i];
    for (int i = 1; i <= N; ++i)
        cin >> l2[i];
    ll res = 0;
    for (int i = 1; i <= N; ++i) {
        if (l1[i] == 0)
            continue;
        res += 3;
        // if i is odd
        if (i % 2 == 1) {
            if (l1[i - 1] == 1)
                res--;
            if (l1[i + 1] == 1)
                res--;
            if (l2[i] == 1)
                res--;
        }
        // if i is even
        else {
            if (l1[i - 1] == 1)
                res--;
            if (l1[i + 1] == 1)
                res--;
        }
    }

    // second line
    for (int i = 1; i <= N; ++i) {
        if (l2[i] == 0)
            continue;
        res += 3;
        // if i is odd
        if (i % 2 == 1) {
            if (l2[i - 1] == 1)
                res--;
            if (l2[i + 1] == 1)
                res--;
            if (l1[i] == 1)
                res--;
        }
        // if i is even
        else {
            if (l2[i - 1] == 1)
                res--;
            if (l2[i + 1] == 1)
                res--;
        }
    }
    cout << res << '\n';
    return 0;
}
