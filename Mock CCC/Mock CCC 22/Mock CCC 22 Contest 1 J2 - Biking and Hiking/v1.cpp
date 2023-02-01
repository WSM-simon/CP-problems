#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        if (c == 'U') {
            if (M > 1)
                M--;
            else if (M == 1)
                M--, cnt++;
            else if (M == 0)
                cnt++;
        } else if (c == 'D') {
            M++;
        } else if (c == 'F') {
            if (M == 0)
                cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}