// there're still 2 cases can't pass
#include <bits/stdc++.h>
#define ll long long
#define ar3 array<long long, 3>
#define f first
#define s second

using namespace std;

const int MxN = 43;
const int MxM = 1e5 + 3;

int N, ans[MxN];
pair<ll, ll> target;
vector<pair<ll, ll>> inst1, inst2;
struct S;
vector<S> mix1, mix2;

struct S
{
    ll x, y, cnt;
    bool operator<(const S &s) const
    {
        if (x != s.x)
            return x < s.x;
        else
            return y < s.y;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> target.f >> target.s;
    for (int i = 0; i < N; ++i)
    {
        pair<ll, ll> tem;
        cin >> tem.f >> tem.s;
        if (i % 2)
            inst1.push_back(tem);
        else
            inst2.push_back(tem);
    }

    int size_inst1 = (int)inst1.size(), size_inst2 = (int)inst2.size();
    // find the mix1
    for (int i = 0; i < (1 << size_inst1); ++i)
    {
        int cnt = 0;
        pair<ll, ll> co = {0, 0};
        for (int j = 0; j < size_inst1; ++j)
            if ((1 << j) & i)
                co.f += inst1[j].f, co.s += inst1[j].s, cnt++;
        mix1.push_back({co.f, co.s, cnt});
    }

    // find the mix2
    for (int i = 0; i < (1 << size_inst2); ++i)
    {
        int cnt = 0;
        pair<ll, ll> co = {0, 0};
        for (int j = 0; j < size_inst2; ++j)
            if ((1 << j) & i)
                co.f += inst2[j].f, co.s += inst2[j].s, cnt++;
        mix2.push_back({co.f, co.s, cnt});
    }

    sort(mix2.begin(), mix2.end());

    int size_mix1 = (int)mix1.size(), size_mix2 = (int)mix2.size();
    for (auto p1 : mix1)
    {
        S obj = {target.f - p1.x, target.s - p1.y, 0};
        auto bounds = equal_range(mix2.begin(), mix2.end(), obj);
        for (auto it = bounds.f; it != bounds.s; ++it)
            ans[p1.cnt + it->cnt]++;
    }

    for (int i = 1; i <= N; ++i)
        cout << ans[i] << '\n';
    return 0;
}
