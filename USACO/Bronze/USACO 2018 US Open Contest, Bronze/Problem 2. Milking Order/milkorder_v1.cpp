#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M, K, pos_cow[MxN], vis[MxN];
vector<int> ordered_cows;
bool is_ordered = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("milkorder.in");
    ofstream fout("milkorder.out");

    fin >> N >> M >> K;
    for (int i = 0; i < M; ++i) {
        int c;
        fin >> c;
        ordered_cows.push_back(c);
        if (c == 1) is_ordered = 1;
    }
    for (int i = 0; i < K; ++i) {
        int r, p;
        fin >> r >> p;
        pos_cow[p] = r;
        vis[r] = p;
    }
    // place reversely
    if (!is_ordered) {
        reverse(ordered_cows.begin(), ordered_cows.end());
        int pos = N;
        for (int c : ordered_cows) {
            if (vis[c]) {
                pos = vis[c];
                continue;
            }
            while (pos_cow[pos])
                pos--;
            pos_cow[pos] = c;
            vis[c] = pos;
        }
        for (int i = 1; i < N; ++i) {
            if (pos_cow[i] == 0) {
                fout << i << '\n';
                return 0;
            }
        }
    } else {
        int pos = 1;
        for (int c : ordered_cows) {
            if (vis[c]) {
                pos = vis[c];
                continue;
            }
            while (pos_cow[pos])
                pos++;
            pos_cow[pos] = c;
            vis[c] = pos;
        }
        fout << vis[1] << '\n';
        return 0;
    }

    return 0;
}