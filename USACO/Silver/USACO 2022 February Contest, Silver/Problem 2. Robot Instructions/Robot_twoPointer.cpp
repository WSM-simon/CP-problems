#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define f first
#define s second

using namespace std;
using ll = long long;

const int MxN = 43;
const ll inf = 1e18 + 3;

ll N, ans[MxN];
pll target;
vector<pll> instr1, instr2;

struct S {
    pll pos;
    ll cnt;
    bool operator<(S tem) { return pos < tem.pos; }
};

inline pll operator+(const pll a, const pll b) { return {a.f + b.f, a.s + b.s}; }
inline pll operator-(const pll a, const pll b) { return {a.f - b.f, a.s - b.s}; }

vector<S> find_subset(vector<pll> v)
{
    vector<S> subset;
    int size_v = v.size();
    for (int i = 0; i < (1 << size_v); ++i) {
        pll p = {0, 0};
        int steps = 0;
        for (int j = 0; j < size_v; ++j)
            if ((i >> j) & 1) p = p + v[j], steps++;
        subset.push_back({p, steps});
    }
    return subset;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> target.f >> target.s;
    for (int i = 0; i < N; ++i) {
        pll tem;
        cin >> tem.f >> tem.s;
        if (i % 2)
            instr1.push_back(tem);
        else
            instr2.push_back(tem);
    }
    vector<S> mix1 = find_subset(instr1), mix2 = find_subset(instr2);
    sort(mix1.begin(), mix1.end());
    sort(mix2.begin(), mix2.end());
    reverse(mix2.begin(), mix2.end());

    // two pointers
    ll pt = 0, size_mix2 = mix2.size();
    pll pre = {inf, inf};
    ll tem_sum[MxN];
    for (S v : mix1) {
        pll diff = target - v.pos;
        if (pre != diff) {
            pre = diff;
            memset(tem_sum, 0, sizeof(tem_sum));
            while (pt < size_mix2 && mix2[pt].pos > diff) ++pt;
            while (pt < size_mix2 && mix2[pt].pos == diff) {
                tem_sum[mix2[pt].cnt]++;
                ++pt;
            }
        }
        for (int i = 0; i < N; ++i) {
            ans[i + v.cnt] += tem_sum[i];
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
