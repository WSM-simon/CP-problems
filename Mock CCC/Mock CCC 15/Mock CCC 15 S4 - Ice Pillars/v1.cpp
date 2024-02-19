#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

bool isValid(int x, int y) {
    if (y == 0)
        return false;
    return !(x % y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << isValid(1, 0);
    return 0;
}