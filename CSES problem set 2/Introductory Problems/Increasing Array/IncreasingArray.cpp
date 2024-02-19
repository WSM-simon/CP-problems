#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

ll N, M;
ll arr[MxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    ll maxn = 0, cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (arr[i] > maxn)
            maxn = arr[i];
        else
            cnt += maxn - arr[i];
    }
    cout << cnt << '\n';
    return 0;
}