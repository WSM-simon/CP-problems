#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

ll N, M;
bool vis[MxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int tem;
        cin >> tem;
        vis[tem] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        if (!vis[i])
            cout << i << '\n';
    }
    return 0;
}