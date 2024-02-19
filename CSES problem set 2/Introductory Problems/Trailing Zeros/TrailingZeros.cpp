#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

ll N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int total_5 = 0;
    for (int i = 5; i <= N; i *= 5) {
        total_5 += N / i;
    }
    cout << total_5 << '\n';
    return 0;
}