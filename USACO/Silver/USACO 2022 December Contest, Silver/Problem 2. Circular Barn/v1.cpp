#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 5e2 + 3;

ll N, vis_p[MxM];
vector<ll> primes = {1};
vector<ll> graph;

// c == 1: john's turn
// c == 0; Nhoj's turn

// return 1 means win
// return -1 means lose
// return 0 means neither win or lose.
int solve(ll pos, ll c = 1) {
    if (graph[pos] == 0)
        return false;
    bool win = 0;
    bool lose = 0;
    bool nwl = 0;
    for (ll p : primes) {
        if (p > graph[pos])
            break;
        graph[pos] -= p;
        if (c == 1) {
            int r = solve(pos, 0);
            if (r == 1)
                lose = 1;
            if (r == -1)
                win = 1;
            if (r == 0)
                nwl = 1;
        }
        if (c == 0) {
            int r = solve(pos + 1, 1);
            if (r == 1)
                lose = 1;
            if (r == -1)
                win = 1;
            if (r == 0)
                nwl = 1;
        }
        graph[pos] += p;
        if (win == 1)
            return 1;
        if (lose == 1)
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (ll i = 2; i < MxM; ++i) {
        if (!vis_p[i]) {
            primes.push_back(i);
            for (ll j = i; j < MxM; j += i)
                vis_p[j] = 1;
        }
    }
    cin >> N;
    for (ll i = 0; i < N; ++i) {
        ll tem;
        cin >> tem;
        graph.push_back(tem);
    }
    // John goes first

    return 0;
}