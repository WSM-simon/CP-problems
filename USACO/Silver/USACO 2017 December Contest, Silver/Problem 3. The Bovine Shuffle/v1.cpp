#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;

int N, nxt[MxN], vis[MxN], cnt = 0;

int cnt_cycle(int n) {
    bool is_cycle = 1;
    vector<int> cycle;
    int cycle_pnt = 0;
    for (int i = n;; i = nxt[i]) {
        if (!vis[i]) {
            vis[i] = 1;
            cycle.push_back(i);
        } else if (vis[i] == 1) {
            cycle_pnt = i;
            break;
        } else if (vis[i] == 2) {
            is_cycle = 0;
            break;
        }
    }
    for (int v : cycle) vis[v] = 2;
    if (is_cycle) {
        int pos = 0;
        while (cycle[pos] != cycle_pnt)
            pos++;
        return (int)cycle.size() - pos;
    } else
        return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");

    fin >> N;
    for (int i = 1; i < N + 1; ++i) {
        fin >> nxt[i];
    }
    for (int i = 1; i < N + 1; ++i) {
        if (!vis[i])
            cnt += cnt_cycle(i);
    }
    fout << cnt;
    return 0;
}