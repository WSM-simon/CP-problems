#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

ll N, M;
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c = ' ';
    int cnt = 1;
    int cnt_max = 1;
    cin >> str;
    for (char t : str) {
        if (t == c) {
            cnt++;
            cnt_max = max(cnt_max, cnt);
        } else {
            cnt = 1;
            c = t;
        }
    }
    cout << cnt_max << '\n';
    return 0;
}