#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int Mx = 103;

int N, tR[Mx], tCost[Mx];
set<int> friends;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int t = -1;
    bool added = 0;
    for (int i = 0; i < N; ++i) {
        char c;
        int n;
        cin >> c >> n;
        if (c == 'W') {
            t += n;
            added = 1;
            continue;
        }
        if (!added)
            t++;
        friends.insert(n);
        if (c == 'R')
            tR[n] = t, added = 0;
        if (c == 'S')
            tCost[n] += t - tR[n], tR[n] = 0, added = 0;
    }
    for (int f : friends)
        cout << f << ' ' << (tR[f] == 0 ? tCost[f] : -1) << '\n';

    return 0;
}