#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

ll N, M;


void hanoi(int n, int src, int aux, int dst) {
    if (n == 1)
        cout << src << ' ' << dst << '\n';
    else{
        hanoi(n-1, src, dst, aux);
        hanoi(1, src, aux, dst);
        hanoi(n-1, aux, src, dst);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    hanoi(N, 1, 2, 3);
    return 0;
}