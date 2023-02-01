#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    ll i, j;
    cin >> i >> j;
    if (abs(i*i - N) < abs(j*j - N))
        cout << 1 << '\n';
    else
        cout << 2 << '\n';   
    return 0;
}