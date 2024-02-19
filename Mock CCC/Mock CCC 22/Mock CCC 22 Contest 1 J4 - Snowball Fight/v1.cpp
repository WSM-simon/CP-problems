#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M, last_throw[MxN];
queue<int> target[MxN];
queue<pair<int, int>> added;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        int t;
        cin >> t;
        target[i].push(t);
    }
    for (int j = 0; j < M; ++j) {
        for (int i = 1; i <= N; ++i) {
            if (target[i].empty())
                continue;
            int t = target[i].front();
            target[i].pop();
            last_throw[i] = t;
            added.push({t, i});
        }
        while(!added.empty()){
            int a,b;
            tie(a, b) = added.front();
            added.pop();
            target[a].push(b);
        }
    }
    for (int i=1;i<=N; ++i){
        cout << last_throw[i] << " \n"[i == N];
    }
    return 0;
}