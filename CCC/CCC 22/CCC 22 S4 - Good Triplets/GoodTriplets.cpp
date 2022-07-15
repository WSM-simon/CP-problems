#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e6 + 3;
const int MxM = 1e6 + 3;

int N, M;
int cir[MxM], prefix[MxM];
set<int> points;
bool is_odd;
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    is_odd = M % 2;
    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        points.insert(p);
        cir[p]++;
    }
    prefix[0] = cir[0];
    for (int i = 1; i < M; ++i) prefix[i] = prefix[i - 1] + cir[i];
    // for the first time, do search the entire circle
    ll partial_ans = 0;
    auto p = points.begin();
    auto p2 = p;
    p2++;
    int seg1 = (M + 1) / 2 - 1 + *p;
    while (*p2 <= seg1) {
        int seg2 = (M / 2 + 1 + *p2);
    }

    // for (int p : points) {
    //     if (p == points.begin()) {
    //         auto p2 = p;
    //         p2++;
    //         int ending =  M/2 + *p;
    //     }
    // }

    return 0;
}