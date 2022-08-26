#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        q.push(i);
    int cnt = 0;
    while (!q.empty()) {
        int f = q.front();
        q.pop(), cnt++;
        if (cnt != M)
            q.push(f);
        else {
            cnt = 0;
            cout << f << ' ';
        }
    }

    return 0;
}