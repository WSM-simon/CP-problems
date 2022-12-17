#include <bits/stdc++.h>
#define ll long long
#define pi 3.1415926

using namespace std;

double N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    double res = 0.333333333 * pi * N * N * M;
    // double res = 3;
    cout << res << '\n';
    return 0;
}
