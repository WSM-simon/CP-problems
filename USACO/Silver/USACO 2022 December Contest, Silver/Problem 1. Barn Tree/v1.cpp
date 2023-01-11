#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 2e5 + 3;
const int MxM = 2e5 + 3;

ll N, cnt = 0, avg = 0;
ll sum = 0;
ll hays[MxN], diff[MxN];
vector<ll> graph[MxN];
vector<array<ll, 3>> steps;

// Find how many hay is needed for a tree with root as "node".
void find_diff(ll node, ll pre = -1) {
    for (ll v : graph[node]) {
        if (v == pre)
            continue;
        find_diff(v, node);
        diff[node] += diff[v];
    }
    diff[node] += hays[node] - avg;
}

// Process positive nodes first, then print backwardly.
// Process neg nodes, and then print them forwardly.
void solve(ll node, ll pre = -1) {
    // classify pos and neg nodes
    vector<ll> pos, neg;
    for (ll v : graph[node]) {
        if (v == pre)
            continue;
        if (diff[v] > 0)
            pos.push_back(v);
        if (diff[v] < 0)
            neg.push_back(v);
        if (diff[v] == 0)
            solve(v, node);
    }

    for (ll v : pos) {
        solve(v, pre = node);
        steps.push_back({v, node, diff[v]});
    }
    for (ll v : neg) {
        steps.push_back({node, v, -diff[v]});
        solve(v, pre = node);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (ll i = 0; i < N; ++i) {
        cin >> hays[i + 1];
        sum += hays[i + 1];
    }
    for (ll i = 0; i < N - 1; ++i) {
        ll k, v;
        cin >> k >> v;
        graph[k].push_back(v);
        graph[v].push_back(k);
    }
    avg = sum / N;

    memset(diff, sizeof(diff), 0);
    find_diff(1);
    solve(1);

    // output
    // reverse(steps.begin(), steps.end());
    cout << steps.size() << '\n';
    for (ll i = 0; i < steps.size(); ++i)
        cout << steps[i][0] << ' ' << steps[i][1] << ' ' << steps[i][2] << '\n';
    return 0;
}