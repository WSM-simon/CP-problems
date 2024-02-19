#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 1e5 + 3;

ll N, M;
int cnt[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    for (char c : s)
        int(cnt[c - 64]++);
    int odd = 0;
    for (int i = 1; i <= 26; ++i)
        if (cnt[i] % 2) {
            if (s.size() % 2 == 0) {
                cout << "NO SOLUTION\n";
                return 0;
            } else if (!odd)
                odd = i;
            else {
                cout << "NO SOLUTION\n";
                return 0;
            }
        }
    if (!odd) {
        for (int i = 1; i <= 26; ++i)
            for (int j = 0; j < cnt[i] / 2; ++j)
                cout << (char)(i + 64);
        for (int i = 26; i > 0; --i)
            for (int j = 0; j < cnt[i] / 2; ++j)
                cout << (char)(i + 64);
    } else {
        for (int i = 1; i <= 26; ++i) {
            if (i == odd) continue;
            for (int j = 0; j < cnt[i] / 2; ++j)
                cout << (char)(i + 64);
        }
        for (int j = 0; j < cnt[odd]; ++j)
            cout << (char)(odd + 64);
        for (int i = 26; i > 0; --i) {
            if (i == odd) continue;
            for (int j = 0; j < cnt[i] / 2; ++j)
                cout << (char)(i + 64);
        }
    }
}