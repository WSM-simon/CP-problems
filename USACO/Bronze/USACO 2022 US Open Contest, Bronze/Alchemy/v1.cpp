#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e3 + 3;
const int MxM = 1e3 + 3;

int N, K;
int metals[MxN];
vector<int> recipes[MxM];

bool make_metal(int x) {
    if (recipes[x].size() == 0)
        return false;
    for (int i : recipes[x]) {
        // in stock
        if (metals[i] >= 1)
            continue;
        // cannot make one metal i
        else if (!make_metal(i))
            return false;
    }
    // make one metal x
    for (int i : recipes[x])
        metals[i]--;
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
