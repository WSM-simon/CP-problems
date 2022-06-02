#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long, long long>
#define f first
#define s second

using namespace std;

const int MxN = 43;
const int MxM = 1e5 + 3;
const int MOD1 = 929;
const int MOD2 = 2e6 + 3;

int N, ans[MxN];
pll goal;
vector<pll> dataIn;

inline pll operator-(pll a, pll b) { return {a.f - b.f, a.s - b.s}; }
inline pll operator+(pll a, pll b) { return {a.f + b.f, a.s + b.s}; }

struct S {
    pll pos;
    ll steps;
};

vector<S> find_subset(vector<pll> v)
{
    vector<S> subset;
    int size_v = v.size();
    for (int i = 0; i < (1 << size_v); ++i) {
        pll p = {0, 0};
        int steps = 0;
        for (int j = 0; j < size_v; ++j)
            if ((i >> j) & 1) {
                p = p + v[j];
                steps++;
            }
        subset.push_back({p, steps});
    }
    return subset;
}

struct myHash {
    size_t operator()(const pll p) const { return (p.f * MOD1 + p.second) % MOD2; }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> goal.f >> goal.s;
    for (int i = 0; i < N; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        dataIn.push_back({t1, t2});
    }
    vector<S> mix1 = find_subset(vector<pll>(dataIn.begin(), dataIn.begin() + N / 2));
    vector<S> mix2 = find_subset(vector<pll>(dataIn.begin() + N / 2, dataIn.end()));
    // sh stands for second half
    // there are sh[(x, y)][n] ways to get to point (x, y) in n steps in mix2
    unordered_map<pll, unordered_map<ll, ll>, myHash> sh;
    // pre-process the second half, make sure there are sh[(x, y)][n] ways to get to point (x, y) in n steps
    for (S v : mix2) ++sh[v.pos][v.steps];

    for (S v1 : mix1) {
        pll diff = goal - v1.pos;
        auto it = sh.find(diff);
        if (it != sh.end()) {
            for (auto [steps, ways] : it->s) {
                ans[v1.steps + steps] += ways;
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
