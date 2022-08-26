#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int M, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    int cnt = 0;
    queue<int> q;
    unordered_set<int> st;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (st.count(x) == 1)
            continue;
        cnt++;
        if (q.size() >= M)
            st.erase(q.front()), q.pop();
        q.push(x), st.insert(x);
    }
    cout << cnt << '\n';
    return 0;
}