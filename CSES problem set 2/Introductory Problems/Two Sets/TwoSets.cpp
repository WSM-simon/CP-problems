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
    if (N % 4 == 3) {
        cout << "YES\n";
        cout << N / 4 * 2 + 1 << '\n';
        for (int i = 1; i <= N / 4; ++i)
            cout << i << ' ' << N - i << ' ';
        cout << N << '\n';
        cout << N / 2 + (N / 2 % 2 ? 1 : 0) << '\n';
        for (int i = N / 4 + 1; i <= N / 2; ++i)
            cout << i << ' ' << N - i << ' ';
    } else if (N % 4 == 0) {
        cout << "YES\n";
        cout << N / 2 << '\n';
        for (int i = 1; i <= N / 4; ++i)
            cout << i << ' ' << N + 1 - i << ' ';
        cout << N / 2 << '\n';
        for (int i = N / 4 + 1; i <= N / 2; ++i)
            cout << i << ' ' << N + 1 - i << ' ';
    } else
        cout << "NO\n";
    return 0;
}