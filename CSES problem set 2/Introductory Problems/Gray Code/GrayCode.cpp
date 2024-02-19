#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

ll N, M;
bitset<16> code;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < (1 << N); i++) {
        cout << "i: " << std::bitset<4>(i) << ' ';
        int b = i >> 1;
        cout << "i >> 1: " << std::bitset<4>(b) << ' ';
        int a = ((i >> 1) ^ i);
        cout << "a: " << std::bitset<4>(a) << '\n';
        // cout << a << '\n';
        // code = ((i >> 1) ^ i);
        // string ans = code.to_string().substr(16 - N, N);
        // cout << code.to_string().substr(16 - N, N) << '\n';
    }

    return 0;
}
