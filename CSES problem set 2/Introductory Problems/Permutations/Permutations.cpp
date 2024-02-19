#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

ll N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    if (N == 1)
        cout << "1\n";
    else if (N <= 3)
        cout << "NO SOLUTION";
    else if (N == 4) {
        cout << "2 4 1 3\n";
    } else {
        for (int i = 1; i <= N; i += 2)
            cout << i << ' ';

        for (int i = 2; i <= N; i += 2)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}