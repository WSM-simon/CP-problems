#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

struct DSU {
    int e[MxN];
    DSU() {
        for (int i = 0; i < MxN; ++i) e[i] = -1;
    }
    int find(int x) {
        return (e[x] < 0 ? x : e[x] = find(e[x]));
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        // if size of x is smaller than size of y
        // swap it
        // the result is that size of x is greater than size of y
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y], e[y] = x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
