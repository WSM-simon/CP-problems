#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long, long long>

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

ll N, black[MxN], white[MxN];
vector<pll> connected;
bool col[MxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        char c;
        cin >> c;
        if (c == 'B') col[i] = 1;
    }
    for (int i = 1; i <= N - 1; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        connected.push_back({t1, t2});
        if (col[t1])
            black[t2]++;
        else
            white[t2]++;
        if (col[t2])
            black[t1]++;
        else
            white[t1]++;
    }

    // badPath of 2 is equal to the number of connected vertices
    ll badPath2 = N - 1;
    // count cases that there are 3 consecutive nodes
    ll badPath3 = 0;
    for (int i = 1; i <= N; ++i) {
        if (col[i])
            badPath3 += white[i] * black[i] + white[i] * (white[i] - 1) / 2;
        else
            badPath3 += white[i] * black[i] + black[i] * (black[i] - 1) / 2;
    }

    ll badPath4 = 0;
    // count cases that there are 4 consecutive nodes
    for (auto [n1, n2] : connected) {
        ll w1 = white[n1], w2 = white[n2];
        ll b1 = black[n1], b2 = black[n2];

        if (col[n1] && col[n2]) badPath4 += w1 * w2;
        if (! col[n1] && ! col[n2]) badPath4 += b1 * b2;
        if (col[n1] && ! col[n2]) badPath4 += (w1 - 1) * (b2 - 1) + w2 * b1;
        if (! col[n1] && col[n2]) badPath4 += w1 * b2 + (w2 - 1) * (b1 - 1);
    }

    cout << N * (N - 1) / 2 - badPath2 - badPath3 - badPath4 << '\n';
    return 0;
}
