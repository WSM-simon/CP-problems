#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

int main() {
    int a, b;
    while (cin >> a >> b) {
        if (b == 0){
            cout << "error\n";
            continue;
        }
        cout << a / b + (2 * (a % b) >= b) << '\n';
    }
    return 0;
}
