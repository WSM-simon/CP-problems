#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, S, T;
vector<pair<char, int>> ins;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> S >> T;
    for (int i = 0; i < N; ++i) {
        char c;
        ll tem;
        cin >> c >> tem;
        ins.push_back({c, tem});
    }
    reverse(ins.begin(), ins.end());
    for (int i = 0; i < N; ++i) {
        T = ~(ins[i].second ^ T);
    }
    int temmm;
    reverse(ins.begin(), ins.end());
    
    for (int i=0;i<N; ++i)
    if (T == S)
        cout << 0 << '\n';
    else
        cout << 1 << '\n';
    return 0;
}