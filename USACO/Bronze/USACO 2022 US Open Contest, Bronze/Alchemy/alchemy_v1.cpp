#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

const int MxN = 1e2 + 3;
const int MxM = 1e2 + 3;

int N, K;
int metals[MxN];
vector<int> recipes[MxN];

bool make_metal(int x) {
    if (recipes[x].empty())
        return false;
    for (int m : recipes[x]) {
        if (metals[m] == 0 && !make_metal(m))
            return false;
        else
            metals[m]--;
    }

    // make one metal x
    metals[x]++;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> metals[i + 1];
    }
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int L, M;
        cin >> L >> M;
        for (int j = 0; j < M; ++j) {
            int t;
            cin >> t;
            recipes[L].push_back(t);
        }
    }
    while (make_metal(N))
        continue;

    cout << metals[N] << '\n';

    return 0;
}
