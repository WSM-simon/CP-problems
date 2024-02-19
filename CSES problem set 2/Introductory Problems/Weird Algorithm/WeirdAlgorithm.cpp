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
    cout << N << ' ';
    while (N != 1) {
        if (N % 2)
            N = N * 3 + 1;
        else
            N /= 2;
        cout << N << ' ';
    }

    return 0;
}