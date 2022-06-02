#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

ll N, black[MxN], white[MxN], badPath = 0;
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
        if (col[t1])
            black[t2]++;
        else
            white[t2]++;
        if (col[t2])
            black[t1]++;
        else
            white[t1]++;
    }

    // counting 3-nodes circumstances
    for (int i = 1; i <= N; ++i) {
        if (col[i])
            badPath += black[i] * white[i] + white[i] * max(0ll, white[i] - 1);
        else
            badPath += black[i] * white[i] + white[i] * max(0ll, black[i] - 1);
    }

    // cout << badPath << '\n';
    cout << N * (N - 1) / 2 - (N - 1) - badPath << '\n';
    return 0;
}
