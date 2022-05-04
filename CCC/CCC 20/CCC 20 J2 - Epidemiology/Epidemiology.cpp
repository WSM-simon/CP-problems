#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

double P, N, R;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> P >> N >> R;
    if (R == 1)
        cout << int(floor(P/N));
    if (R > 1)
        cout << int(floor(log(P*(R-1)/N + 1) / log(R)));
    if (R == 0 && P == N)
        cout << 0 << '\n';
    return 0;
}
