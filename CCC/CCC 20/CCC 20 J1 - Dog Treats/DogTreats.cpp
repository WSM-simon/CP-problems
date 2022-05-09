#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int S, M, L;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S >> M >> L;
    int ans = S + 2 * M + 3 * L;
    if (ans >= 10)
        cout << "happy";
    else
        cout << "sad";
    return 0;
}
