#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, mx = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    N = (int)s.size();
    for (int i = 0; i < N; ++i) {
        for (int j = N; j > 0; --j) {
            string sub = s.substr(i, j - i);
            string re_sub(sub);
            reverse(re_sub.begin(), re_sub.end());
            if (sub == re_sub) {
                if (j - i > mx)
                    mx = j - i;
                break;
            }
        }
    }
    cout << mx << '\n';
    return 0;
}