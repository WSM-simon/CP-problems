#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 50;

int N, M;
unordered_set<int> rows[MxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        string s = "";
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            s += c;
        }
        // stoi can convert binary string to int
        int bin = stoi(s, nullptr, 2);
        // cout << bin << '\n';
        rows[i].insert(bin);
    }
    for (int i = 1; i < N; ++i) {
        int num = *rows[i].begin();
        for (int num2 : rows[i - 1]) {
            rows[i].insert(num ^ num2);
        }
    }
    cout << rows[N - 1].size() << '\n';
    return 0;
}