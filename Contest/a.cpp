#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

void solve() {
    int w, h;
    cin >> w >> h;
    if (max(w, h) >= 4 && w>=2 && w*h>=7)
        cout << "good\n";
    else
        cout << "bad\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while (N--)
        solve();

    return 0;
}