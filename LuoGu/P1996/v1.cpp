#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    list<int> linkedlist;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        linkedlist.push_back(i);
    if (M > N)
        M %= N;
    auto p = linkedlist.begin();
    int cnt = 0;
    while (!linkedlist.empty()) {
        cnt++;
        if (cnt == M) {
            cout << *p << ' ';
            auto p2 = p;
            p--;
            linkedlist.erase(p2);
            cnt = 0;
        }
        if (++p == linkedlist.end())
            p = linkedlist.begin();
    }
    cout << '\n';
    return 0;
}